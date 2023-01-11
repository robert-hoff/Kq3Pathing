
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






