@echo off
:: 두 번째 화면(가로/주모니터)만 남기고 1번(세로) 끄기
%windir%\System32\DisplaySwitch.exe /external
exit