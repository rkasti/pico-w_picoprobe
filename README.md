# pico-w_picoprobe
sample project to get started with a pico-w and picoprobe inside vscode
# Setup
1. Install [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug) extension inside vscode
2. Clone the repo
3. Read and follow the instructions of `Appendix A: Using Picoprobe` inside [getting-started-with-pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
4. Set enviroment variable `PICO_SDK_PATH` to the root folder of the pico-sdk and `OPENOCD_TCL` to the tcl folder inside openocd source
# Build
From project root directory:
```
mkdir build
cd build
cmake ..
```
Inside vscode open the debug menu and hit run on the `Pico Debug` profile
