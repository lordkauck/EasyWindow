# __EasyWindow Overview__
**A library written in C aimed at making Windows GUI programs easier.**

## __Technical information__:
- Does not use exceptions
- Does not depend on other libraries outside of native libraries
- Does not require CRT
- Easy to implement into a class wrapper
- Custom Window Message Procedure support (useful for ImGui)

__**Currently only supports Windows platform.**__
  
## __How to use EasyWindow__:
Include the proper `EasyWindow.lib` library file in your projects dependencies.
If you are making an x86 build, include the library from the `x86` directory, likewise, include the library from the `x64` directory if you are making an x64 build.
Include the proper `EasyWindow.dll` library file in your project binary dependencies. 
If you are making an x86 build, include the dll library from the `x86` directory, likewise, include the dll library from the `x64` directory if you are making an x64 build.
Then include the `EasyWindow.h` header file in your project. 

### __Example code below__:
```cpp
#include <stdio.h>
#include "EasyWindow.h"

bool g_closed = false;
static void close_app(void) { g_closed = true; }
int main(int argc, char* argv[]) {
    EasyWindow window = EasyWindowCreateWindow("EasyWindow Test", 1280.0f, 720.0f, 0u);
    EasyWindowSetCloseCallback(window,
        [](EasyWindow window) {
           close_app();
        }
    );

    while(!g_closed) {
         EasyWindowPollEvents();
    }
    EasyWindowDestroyWindow(window);
    return 0;
}
```

## Build from source:

**Windows (Visual Studio)**:

Download the source code, open up the viusal studio solution file and build it from there.

