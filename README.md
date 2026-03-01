> [!WARNING]  
> **This project has been deprecated and archived.**
>
> WCECL was originally designed as an x86 Windows CE compatibility layer, but in practice there are virtually no x86 Windows CE applications in existence. The millions of real WinCE apps out there are all ARM binaries, which WCECL was never designed to handle.
>
> This project has been succeeded by **[CERF (Windows CE Runtime Foundation)](https://github.com/dz333n/cerf)** — a full ARM CPU emulator and Win32 API compatibility layer that can actually run real Windows CE ARM applications on modern x64 desktop Windows.
>
> This repository is kept for historical purposes only and will not receive any further updates.

# Windows CE Compatibility Layer (WCECL)

![Improvised Logo](logo.png)

Use WCECL to run original Windows CE applications on desktop Windows.

## This project includes

- **COREDLL**: a library that wraps Windows CE APIs and redirects calls to desktop Win32 APIs
- **SubsystemTool**: a program that allows you to modify subsystem attributes in portable executables (.EXEs)


### Notes

- ⚠️ The project is at an early stage of development. Only one application has been confirmed to work so far.
- 💩 Contains bad code!
- 🙂 Contributions are welcome!

Visit project [wiki](https://github.com/dz333n/wcecl/wiki) for details.

## Downloads

Open the workflow status link below, open the latest run, scroll to the bottom, and download the desired artifacts.

[![build](https://github.com/dz333n/wcecl/actions/workflows/build.yml/badge.svg)](https://github.com/dz333n/wcecl/actions/workflows/build.yml)
