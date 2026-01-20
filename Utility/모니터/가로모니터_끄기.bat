@echo off
:: 1번(세로)만 켜고, 2번(가로) 끄기 (PC 화면만 모드)
%windir%\System32\DisplaySwitch.exe /internal
exit