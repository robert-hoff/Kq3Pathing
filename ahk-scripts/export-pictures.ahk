; scripts for automating picture exports from WinAGI

counter := 143

sc029 & r::
  showToolTipz("reloading")
  sleep 300
  reload
  ; send {F12}
  return

ShowToolTipz(toolTipText, delay = 2000) {
  tooltip, %toolTipText%
  ; settimer, removetooltipz, %delay%
}


sc029 & 1::
  loop 1 {
    send ^e
    ; sleep 1000
    ; mouseclick L, 205, 66
    sleep 500
    send {right}
    sleep 100
    send {tab}
    sleep 100
    send {tab}
    sleep 100
    send {tab}
    sleep 100
    send {tab}
    sleep 100
    send {tab}
    sleep 100
    send {return}
    sleep 400
    send room%counter%
    counter := counter + 1
    sleep 500
    send {return}
    sleep 1000
    send {return}
    sleep 500
    mouseclick
    sleep 300
    send {down}
    sleep 500
  }
  return

; script for exporting priority data
sc029 & 9::
  loop 10 {
    send ^e
    ; sleep 1000
    ; mouseclick L, 205, 66
    sleep 500
    send {right}
    sleep 200
    send {tab}
    sleep 200
    send {down}
    sleep 200
    send {tab}
    sleep 200
    send 2
    sleep 200
    send {del}
    sleep 200
    send {tab}
    sleep 100
    send {tab}
    sleep 100
    send {tab}
    sleep 100
    send {return}
    sleep 400
    send room%counter%
    counter := counter + 1
    sleep 500
    send {return}
    sleep 3000
    send {return}
    sleep 500
    mouseclick
    sleep 300
    send {down}
    sleep 500
  }
  return



