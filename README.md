#  Running the Program

## 1. The easiest way is to download QT Creator and build with the IDE. 

### 1.1 Prerequisites

Make sure you have Qt Creator installed and have set up the necessary compiler. https://www.qt.io/offline-installers

### 1.2 Opening the Project

1. Open Qt Creator.
2. Click on "File" -> "Open File or Project".
3. In the dialog that pops up, navigate to your project folder and select the project file (usually ending with `.pro`).
4. Click "Open".

### 1.3 Building the Project

1. Once your project is opened, Qt Creator will display it in the editor.
2. Click on the green play button (usually labeled "Run") in the lower-left corner of Qt Creator, or press `Ctrl+R`.
3. Qt Creator will build your project and run it. Any errors or warnings encountered during the build process will be displayed in the "Issues" pane at the bottom of the window.
4. If the build is successful, your program should start running.


## 2. Download qmake and make to run the program

### Prerequisites

Ensure that you have Qt installed on your system and that qmake and make are accessible from the command line.

### Compiling the Project

1. Open a terminal or command prompt.
2. Navigate to your project directory using the `cd` command.
3. Run `qmake` to generate the makefile for your project based on the `.pro` file.

```qmake gui_test.pro```
4. Run `make` to compile your project using the generated makefile.

### Running the Program
```make```
1. After successful compilation, navigate to the directory where your executable was created.
2. Run the executable from the command line by typing its name and pressing Enter.
```./gui_test```
