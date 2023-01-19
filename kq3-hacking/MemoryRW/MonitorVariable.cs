using System.Diagnostics;
using static kq3_hacking.MemoryRW.Kq3AddressPointers;

namespace kq3_hacking.MemoryRW
{
    public partial class MonitorVariable : Form
    {
        public MonitorVariable()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.Manual;
            Location = new Point(500, 200);
            this.Text = "Data monitor";
            this.Load += OnFormLoad;
        }

        private void OnFormLoad(object sender, System.EventArgs e)
        {
            Thread trd = new(new ThreadStart(this.ThreadSampleRandomSeed));
            trd.IsBackground = true;
            trd.Start();
        }

        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == Keys.Escape)
            {
                requestClose = true;
                Close();
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }

        private Kq3ReadWrite kq3ReadWrite = new Kq3ReadWrite();
        private static bool requestClose = false;
        // in ms, low not to miss samples
        private int THREAD_INTERVAL = 10;

        private void ThreadSampleRandomSeed()
        {
            List<PlayerXY> seedValuesSeen = new();
            while (!requestClose)
            {
                PlayerXY playerXY = new PlayerXY(kq3ReadWrite);
                if (seedValuesSeen.Count == 0 || seedValuesSeen.Last().DataChangedCondition(playerXY))
                {
                    seedValuesSeen.Add(playerXY);
                    Debug.WriteLine($"{playerXY}");
                }

                Thread.Sleep(THREAD_INTERVAL);
            }
        }

        class PlayerXY
        {
            Kq3ReadWrite cotlReadWrite;

            int playerX;
            int playerY;

            public PlayerXY(Kq3ReadWrite cotlReadWrite)
            {
                this.cotlReadWrite = cotlReadWrite;
                playerX = cotlReadWrite.ReadByte(PLAYER_XPOS_PTR);
                playerY = cotlReadWrite.ReadByte(PLAYER_YPOS_PTR);

            }

            public bool DataChangedCondition(PlayerXY ed0_prev)
            {
                return playerX != ed0_prev.playerX || playerY != ed0_prev.playerY;
            }

            public override string ToString()
            {
                return $"playerXY = ({playerX},{playerY})";
            }
        }
    }
}



