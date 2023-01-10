namespace kq3_hacking
{
    public partial class TestForm : Form
    {
        public TestForm()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.Manual;
            Location = new Point(500, 100);
            Text = "Kq3 Hacking";
            Load += OnFormLoad;
        }

        private void OnFormLoad(object sender, System.EventArgs e)
        {
            Thread trd = new(new ThreadStart(this.ThreadBackgroundProcess));
            trd.IsBackground = true;
            trd.Start();
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            requestClose = true;
            Thread.Sleep(300);
        }

        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == Keys.Escape)
            {
                Close();
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }


        private bool requestClose = false;

        private void ThreadBackgroundProcess()
        {
            while (!requestClose)
            {

                Thread.Sleep(50);
            }
        }
    }
}

