# mdstool - Console Edition (by genBTC)

This program has been forked from https://github.com/vusec/ridl on 5/15/19<br>
All GUI dependencies such as X11, Freetype, Nuklear and STB have all been removed.<br>
And it is now a text only, console / terminal based program.<br>
It works on Windows and Linux, (tested both myself).<br>
![mdstool+Linux_2019-05-15_00-05-24](https://user-images.githubusercontent.com/3683744/57747844-415ff580-76a5-11e9-9d01-f10bdb70ae21.png)
<br>
## Instructions for compiling. (You need cmake!)

`git clone https://github.com/genBTC/ridl`<br>
`cd ridl`<br>
`mkdir build`<br>
`cd build`<br>
`cmake ..`<br>
`cmake --build .`<br>
`./mdstool` or `mdstool.exe`<br>

### Notes

Conversion went smoothly, except there is one weird error involving show_ssb_tab(&spectre_info) which is actually expecting "ssb_info" (the section labeled "Speculative Store Bypass:") and the SSB query happens differently on linux than windows, so I might need outside help confirming the validity of this code.
I've found 2 bugs, involving which struct fields the program outputs. These have been submitted upstream with pull-requests (#2 and #3) and already merged into my repo.

### Code Audit

The original and my own version both seem safe to run on any machine and has no malicious intent. If the author had produced a console version I would not have needed to fork it.
