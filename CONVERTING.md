# Windows CE Compatibility Layer
# Converting CE PEs to Win32 PEs

To do this, you have to put executables and linked libraries **(ignore coredll.dll)** ((use software like Dependency Walker to get them)* together. Then, you have to edit PE files header in some way. Namely, change subsystem from **9** (WinCE GUI) to **2** (Win32 GUI).

Subsystem list:

| Constant Name | Value | Description |
| ------------- | ----- | ----------- |
| IMAGE_SUBSYSTEM_UNKNOWN | 0 | Unknown subsystem |
| IMAGE_SUBSYSTEM_NATIVE | 1 | No subsystem required (device drivers and native system processes) |
| IMAGE_SUBSYSTEM_WINDOWS_GUI | 2 | **Windows GUI** subsystem |
| IMAGE_SUBSYSTEM_WINDOWS_CUI | 3 | **Windows CUI** (console) subsystem |
| IMAGE_SUBSYSTEM_OS2_CUI | 5 | OS/2 CUI (console) subsystem |
| IMAGE_SUBSYSTEM_POSIX_CUI | 7 | POSIX CUI (console) subsystem |
| IMAGE_SUBSYSTEM_WINDOWS_CE_GUI | 9 | **Windows CE GUI** subsystem |
| IMAGE_SUBSYSTEM_EFI_APPLICATION | 10 | EFI application |
| IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER | 11 | EFI driver with boot services |
| IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER | 12 | EFI driver with run-time services |
| IMAGE_SUBSYSTEM_EFI_ROM | 13 | EFI ROM image |
| IMAGE_SUBSYSTEM_XBOX | 14 | Xbox subsystem |
| IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION | 16 | Windows boot application |

*In future, it's better to have own tool to do this automatically.*

Then, put compiled ``coredll.dll`` there, and executables are ready to start!
