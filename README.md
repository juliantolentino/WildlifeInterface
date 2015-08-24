# WildlifeInterface

Summary: This is an instruction for compiling the wildlife interface code on Qt. 

You will need to download Qt online. Have sufficient space for the installation of Qt. The windows version will take about 5 GB of space. The interface code and GUI elements are in the "Interface" folder. The executable and dll files must stay in the same directory.

If video does not appear after pressing "Play", the install the proper codec pack. The K-Lite Codec Pack Standard is included in the "Interface Windows Executable" folder. If possible, check and install the latest version at www.codecguide.com/download_kl.htm.

How to Compile Interface Code in Qt

1.	 Download, install, and open the latest version of Qt Open Source from www.qt.io/download/.
2.	Open "Interface.pro" in Qt
a.	The interface code and GUI elements must be in the same folder.
b.	Open the .pro file in the said folder.
c.	Select "No" when asked to load user settings from the "Interface.pro.user" file.
d.	Select the highest version of the desktop kit and select "Configure Project".
3.	Uncheck "Shadow Build" under the "Projects" tab on the left toolbar
4.	Under "Build" on the menu bar, select "Clean All". After completion, select "Run qmake". After completion, select "Build All".
5.	For future compilations, only the "Build All" selection is required. The green play button on the left toolbar provides the same functionality. 

