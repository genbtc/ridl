Microsoft Windows instructions
==============================

1. Clone this git repository: (git must be installed)

```
Open a command prompt: Start > Run... > cmd.exe
git clone https://github.com/genBTC/ridl
cd ridl\tool
```

2. Install the dependencies (downloads 2 submodules, Nuklear & STB):

```
git submodule init
git submodule update
```

3. Generate and Build (GUI) - from inside Visual Studio 2017/2019 using CMake:

```
File menu > Open > Folder ...
CMake menu > Build All...
Some warnings during the build DO appear, but it should say "[60/60]" and "Build succeeded." 
```


(3). Extra Visual Studio build tips for newbies:

In the icon toolbar, look for "x64-Debug (default)" dropdown menu, click it, choose "Manage Configurations...." then pick "x64-Release"<br>
In the following text file that appears, (CMakeSettings.json), change the default build root directory:<br>
`    from:   "buildRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",`<br>
`      to:   any new directory name of your choice. (use double backslashes)`<br>
File menu > Save. CMake menu > Rebuild All...<br>
Now the .exe's get compiled and built into that directory.<br>
Navigate to that build directory by: <br>
    CMake menu > Cache (x64-Release) > Open Cache Folder > mdstool<br>
or open a command prompt:<br>
    Start > Run... > cmd.exe <br>
    cd %USERPROFILE%\CMakeBuilds\ {uniqueGUIDhere} \ build \ {platform-target-name} \ <br>
    for example: C:\Users\EOFL\CMakeBuilds\ca2faf2d-b933-9a3d-819b-810636e28730\build\x64-Release\ <br>
    or navigate to the custom build root directory you chose above. <br>
Only the .exe files are needed when re-distributing.<br>
<br>

3. Alternately, Generate and Build (command line) - using CMake and VS:

```
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_C_FLAGS="/W0"
cmake --build . --config "Release"
cd "Release"
```
Options: <br>
VS version:  (change to 16 2019 instead of 15 2017) <br>
VS platform: (remove Win64 for 32-bit instead) <br>
option 1: (change to Debug or RelWithDebInfo instead of Release) <br>
option 2: (remove -DCMAKE_C_FLAGS="/W0" to not hide all compiler warnings)<br>

4. Done. Run the .exe: mdstool.exe or mdstool-cli.exe or .\mdstool.exe (powershell) <br>
(the mdstool-cli.exe version will auto-exit/disappear when double-clicked from Explorer, it MUST be run from a pre-existing command prompt). <br>
<br>

5. Questions? 

<br>
The new -cli version now has colors, and will produce garbled text output _IF_ your regular old Windows command prompt (or even powershell) cannot support color. <br>
A 3rd-party terminal program like "ConEMU" with color support is recommended in such a case...<br>
Also, I am hosting an my original, text-only, no-color, command line version here @ [oldversion1-CLI branch](https://github.com/genbtc/ridl/tree/oldversion1-CLI) <br>
TODO: Note that this is old code and has not been updated since the original May 15, 2019 release.<br>
<br>

Linux/Mac/BSD instructions.
=====
Unchanged. See the original documentation @ [README.MD](https://github.com/vusec/ridl/tree/master/tool)


FAQ
===

Q) Can I run this in a VM?

No. This program relies on the `cpuid` instruction, which might report the wrong information in a VM. 
Make sure to run this on the actual hardware, not using virtualization.

Q) What about Hyperthreading ?

If your hyperthreading is already disabled, this tool may still report it as vulnerable (false positive). Disabling HT in BIOS/UEFI manually protects you.