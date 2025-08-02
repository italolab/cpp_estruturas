@echo off

set root_dir=%~dp0%

set estruturas_testes_proj_dir=%root_dir%EstruturasTestes
set estruturas_proj_dir=%root_dir%Estruturas
set utils_proj_dir=%root_dir%Utils
set testesunit_proj_dir=%root_dir%TestesUnit

set utils_dll_file_name=Utils.dll
set testes_unit_dll_file_name=TestesUnit.dll
set estruturas_dll_file_name=Estruturas.dll

set app_file_name=EstruturasTestes.exe
set app_file=%estruturas_testes_proj_dir%\%app_file_name%

set utils_proj_src=%utils_proj_dir%\src
set utils_proj_include=%utils_proj_dir%\dll\include
set utils_proj_dll_file=%utils_proj_dir%\bin\Debug\%utils_dll_file_name%

set estruturas_proj_src=%estruturas_proj_dir%\src
set estruturas_proj_include=%estruturas_proj_dir%\dll\include
set estruturas_proj_dll_file=%estruturas_proj_dir%\bin\Debug\%estruturas_dll_file_name%

set testesunit_proj_src=%testesunit_proj_dir%\src
set testesunit_proj_include=%testesunit_proj_dir%\dll\include
set testesunit_proj_dll_file=%testesunit_proj_dir%\bin\Debug\%testesunit_dll_file_name%

set estruturas_testes_proj_include=%estruturas_testes_proj_dir%\include


if %1==limpar (
    call :limpa_tudo
) else if %1==build (
    call :build_e_copia_tudo
) else if %1==exec (
    call :build_e_copia_tudo
    call :exec_app
) else if %1==buildutils (
    call :build_e_copia_utils
    rem call :compila_estruturas_testes
    rem call :exec_app
) else if %1==buildtestesunit (
    call :build_e_copia_testesunit
    rem call :compila_estruturas_testes
    rem call :exec_app
) else if %1==buildestruturas (
    call :build_e_copia_estruturas
    rem call :compila_estruturas_testes
    rem call :exec_app
) else if %1==app (
    call :exec_app
) else if %1==pushall (
    call :pushall
)

goto :fim

:exec_app
    @echo on
    echo %app_file%
    %app_file%
    @echo off
exit /b 0

:limpa_tudo
    call %utils_proj_dir%\exec.bat limpar
    call %testesunit_proj_dir%\exec.bat limpar
    call %estruturas_proj_dir%\exec.bat limpar
    call %estruturas_testes_proj_dir%\exec.bat limpar
exit /b 0

:build_e_copia_tudo
    call :limpa_estruturas_testes

    call :build_e_copia_utils
    call :build_e_copia_testesunit
    call :build_e_copia_estruturas
    call :compila_estruturas_testes
exit /b 0

:build_e_copia_utils
    rem call %utils_proj_dir%\exec.bat compilar

    xcopy %utils_proj_src% %estruturas_testes_proj_include% /s /q /y
    del /s /q %estruturas_testes_proj_include%\*.cpp

    copy %utils_proj_dll_file% %estruturas_testes_proj_dir% /y

    echo Foi realizada a copia dos arquivos da biblioteca Utils.dll
exit /b 0

:build_e_copia_testesunit
    rem call %testesunit_proj_dir%\exec.bat compilar

    xcopy %testesunit_proj_src% %estruturas_testes_proj_include% /s /q /y
    del /s /q %estruturas_testes_proj_include%\*.cpp

    copy %testesunit_proj_dll_file% %estruturas_testes_proj_dir%

    echo Foi realizada a copia dos arquivos da biblioteca TestesUnit.dll
exit /b 0

:build_e_copia_estruturas
    rem call %estruturas_proj_dir%\exec.bat compilar

    xcopy %estruturas_proj_src% %estruturas_testes_proj_include% /s /q /y
    del /s /q %estruturas_testes_proj_include%\*.cpp

    copy %estruturas_proj_dll_file% %estruturas_testes_proj_dir%

    echo Foi realizada a copia dos arquivos da biblioteca Estruturas.dll
exit /b 0

:limpa_estruturas_testes
    call %estruturas_testes_proj_dir%\exec.bat limpar
exit /b 0

:compila_estruturas_testes
    call %estruturas_testes_proj_dir%\exec.bat compilar
exit /b 0

:pushall
    set /p msg="Commit MSG: "

    cd %utils_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main

    cd %estruturas_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main

    cd %testesunit_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main

    cd %estruturas_testes_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main
exit /b 0

:fim
if ErrorLevel = 1 echo Houve um erro.
