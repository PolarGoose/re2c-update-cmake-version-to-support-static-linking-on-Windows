Function Info($msg) {
  Write-Host -ForegroundColor DarkGreen "`nINFO: $msg`n"
}

Function Error($msg) {
  Write-Host `n`n
  Write-Error $msg
  exit 1
}

Function CheckReturnCodeOfPreviousCommand($msg) {
  if(-Not $?) {
    Error "${msg}. Error code: $LastExitCode"
  }
}

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$ProgressPreference = "SilentlyContinue"

$gitRepoRoot = Resolve-Path "$PSScriptRoot/.."
$buildDir = "$gitRepoRoot/.build_static_Windows_binary"

Info "Find Visual Studio installation path"
$vswhereCommand = Get-Command -Name "${Env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
$installationPath = & $vswhereCommand -prerelease -latest -property installationPath

Info "Open Visual Studio 2022 Developer PowerShell"
& "$installationPath\Common7\Tools\Launch-VsDevShell.ps1" -Arch amd64

Info "Remove '$buildDir' folder if it exists"
Remove-Item $buildDir -Force -Recurse -ErrorAction SilentlyContinue
New-Item $buildDir -Force -ItemType "directory" > $null

Info "Cmake generate cache"
cmake `
  -S $gitRepoRoot `
  -B $buildDir `
  -D CMAKE_BUILD_TYPE=Release `
  -D CMAKE_MSVC_RUNTIME_LIBRARY=MultiThreaded `
  -D RE2C_BUILD_RE2D=0 `
  -D RE2C_BUILD_RE2GO=0 `
  -D RE2C_BUILD_RE2HS=0 `
  -D RE2C_BUILD_RE2JAVA=0 `
  -D RE2C_BUILD_RE2JS=0 `
  -D RE2C_BUILD_RE2OCAML=0 `
  -D RE2C_BUILD_RE2PY=0 `
  -D RE2C_BUILD_RE2RUST=0 `
  -D RE2C_BUILD_RE2V=0 `
  -D RE2C_BUILD_RE2ZIG=0 `
  -D RE2C_BUILD_TESTS=0
CheckReturnCodeOfPreviousCommand "cmake cache failed"

Info "Cmake build"
cmake --build $buildDir
CheckReturnCodeOfPreviousCommand "cmake build failed"
