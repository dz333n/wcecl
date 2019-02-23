# Windows CE Compatibility Layer
# Converting CE PEs to Win32 PEs

To do this, you have to put executables and linked libraries **(ignore coredll.dll)** ((use software like Dependency Walker to get them)* together. Then, you have to edit PE files header in some way. Namely, change subsystem from **9** (WinCE GUI) to **2** (Win32 GUI).

![image](https://user-images.githubusercontent.com/25367511/53287370-c95bf080-3783-11e9-8a00-3b4fe3c193f3.png)

*In future, it's better to have own tool to do this automatically.*

Then, put compiled ``coredll.dll`` there, and executables are ready to start!
