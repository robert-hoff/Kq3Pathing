
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

; -- set line endings for files in Visual studio
sc029 & 1::
  loop 10 {
    send {enter}
    sleep 200
    send !e
    sleep 200
    send v
    sleep 200
    send {up}
    sleep 100
    send {up}
    sleep 100
    send {right}
    sleep 100
    send {down}
    sleep 100
    send {enter}
    sleep 400
    send ^s
    sleep 400
    send ^w
    sleep 400
    send {down}
  }
  return



; -- autoformat only, select all and apply Ctrl K,D
sc029 & 8::
  loop 50 {
    send {enter}
    sleep 200
    send ^a
    sleep 200
    send ^k
    sleep 200
    send ^d
    sleep 200
    send ^s
    sleep 500
    send ^w
    sleep 200
    send {down}

  }
  return


; -- autoformat with file replacement on Ctrl+h
sc029 & 9::
  loop 11 {
    send {enter}
    sleep 200
    send ^h
    sleep 200
    send !a
    sleep 200
    send {esc}
    sleep 200
    send ^a
    sleep 200
    send ^k
    sleep 200
    send ^d
    sleep 200
    send ^s
    sleep 500
    send ^w
    sleep 200
    send {down}

  }
  return






