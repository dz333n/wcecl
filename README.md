# Windows CE Compatibility Layer
## WinCE API <-> Win32 API Translator

# What is this?
Windows CE API is almost the same as Win32 API. Windows CE uses the same file format as Windows - Portable Executable. We can change subsystem in header to get it to work on any Windows-compatible OS. 

## coredll and kernel32
The 1st library is the clone of the 2nd - it contains all operating system's API functions. Currently this project realizes a translator of coredll callings to related Win32 libraries (kernel32, user32, etc.).

# How to convert Windows CE ``.exe``s to Win32?
See [Converting](CONVERTING.md)

# Credits
 - Created by [Yaroslav Kibysh / Dz3n](https://github.com/feel-the-dz3n)
 - [Nikita Ivanov / osdever](https://github.com/osdeverr)
 - Special thanks to [Stanislav Motylkov / Stas'M](https://github.com/binarymaster), he inspired me to make this.
