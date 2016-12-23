@echo off
rem THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
rem ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
rem THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
rem PARTICULAR PURPOSE.
rem
rem Copyright (c) Microsoft Corporation. All rights reserved.
rem
rem Modified by THOTH Speed Engineers (c)
rem Author: Dwight Goins
rem Purpose: Change the compiled SpriteEffect.fx to support DirectX 5_0 for Render Target Array support
rem You can find fxc.exe in the C:\Program Files (x86)\Windows Kits\10\bin\x86 by default

setlocal
set error=0

if %1.==xbox. goto continuexbox
if %1.==. goto continue
echo usage: CompileShaders [xbox]
exit /b

:continuexbox
set XBOXFXC="%XboxOneXDKLatest%xdk\FXC\amd64\FXC.exe"
if exist %XBOXFXC% goto continue
set XBOXFXC="%XboxOneXDKBuild%xdk\FXC\amd64\FXC.exe"
if exist %XBOXFXC% goto continue
set XBOXFXC="%DurangoXDK%xdk\FXC\amd64\FXC.exe"
if not exist %XBOXFXC% goto needxdk

:continue
call :CompileShader%1 AlphaTestEffect vs VSAlphaTest
call :CompileShader%1 AlphaTestEffect vs VSAlphaTestNoFog
call :CompileShader%1 AlphaTestEffect vs VSAlphaTestVc
call :CompileShader%1 AlphaTestEffect vs VSAlphaTestVcNoFog

call :CompileShader%1 AlphaTestEffect ps PSAlphaTestLtGt
call :CompileShader%1 AlphaTestEffect ps PSAlphaTestLtGtNoFog
call :CompileShader%1 AlphaTestEffect ps PSAlphaTestEqNe
call :CompileShader%1 AlphaTestEffect ps PSAlphaTestEqNeNoFog

call :CompileShader%1 BasicEffect vs VSBasic
call :CompileShader%1 BasicEffect vs VSBasicNoFog
call :CompileShader%1 BasicEffect vs VSBasicVc
call :CompileShader%1 BasicEffect vs VSBasicVcNoFog
call :CompileShader%1 BasicEffect vs VSBasicTx
call :CompileShader%1 BasicEffect vs VSBasicTxNoFog
call :CompileShader%1 BasicEffect vs VSBasicTxVc
call :CompileShader%1 BasicEffect vs VSBasicTxVcNoFog

call :CompileShader%1 BasicEffect vs VSBasicVertexLighting
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingBn
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingVc
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingVcBn
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingTx
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingTxBn
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingTxVc
call :CompileShader%1 BasicEffect vs VSBasicVertexLightingTxVcBn

call :CompileShader%1 BasicEffect vs VSBasicOneLight
call :CompileShader%1 BasicEffect vs VSBasicOneLightBn
call :CompileShader%1 BasicEffect vs VSBasicOneLightVc
call :CompileShader%1 BasicEffect vs VSBasicOneLightVcBn
call :CompileShader%1 BasicEffect vs VSBasicOneLightTx
call :CompileShader%1 BasicEffect vs VSBasicOneLightTxBn
call :CompileShader%1 BasicEffect vs VSBasicOneLightTxVc
call :CompileShader%1 BasicEffect vs VSBasicOneLightTxVcBn

call :CompileShader%1 BasicEffect vs VSBasicPixelLighting
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingBn
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingVc
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingVcBn
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingTx
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingTxBn
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingTxVc
call :CompileShader%1 BasicEffect vs VSBasicPixelLightingTxVcBn

call :CompileShader%1 BasicEffect ps PSBasic
call :CompileShader%1 BasicEffect ps PSBasicNoFog
call :CompileShader%1 BasicEffect ps PSBasicTx
call :CompileShader%1 BasicEffect ps PSBasicTxNoFog

call :CompileShader%1 BasicEffect ps PSBasicVertexLighting
call :CompileShader%1 BasicEffect ps PSBasicVertexLightingNoFog
call :CompileShader%1 BasicEffect ps PSBasicVertexLightingTx
call :CompileShader%1 BasicEffect ps PSBasicVertexLightingTxNoFog

call :CompileShader%1 BasicEffect ps PSBasicPixelLighting
call :CompileShader%1 BasicEffect ps PSBasicPixelLightingTx

call :CompileShader%1 DualTextureEffect vs VSDualTexture
call :CompileShader%1 DualTextureEffect vs VSDualTextureNoFog
call :CompileShader%1 DualTextureEffect vs VSDualTextureVc
call :CompileShader%1 DualTextureEffect vs VSDualTextureVcNoFog

call :CompileShader%1 DualTextureEffect ps PSDualTexture
call :CompileShader%1 DualTextureEffect ps PSDualTextureNoFog

call :CompileShader%1 EnvironmentMapEffect vs VSEnvMap
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapBn
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapFresnel
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapFresnelBn
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapOneLight
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapOneLightBn
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapOneLightFresnel
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapOneLightFresnelBn
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapPixelLighting
call :CompileShader%1 EnvironmentMapEffect vs VSEnvMapPixelLightingBn

call :CompileShader%1 EnvironmentMapEffect ps PSEnvMap
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapNoFog
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapSpecular
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapSpecularNoFog
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapPixelLighting
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapPixelLightingNoFog
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapPixelLightingFresnel
call :CompileShader%1 EnvironmentMapEffect ps PSEnvMapPixelLightingFresnelNoFog

call :CompileShader%1 SkinnedEffect vs VSSkinnedVertexLightingOneBone
call :CompileShader%1 SkinnedEffect vs VSSkinnedVertexLightingOneBoneBn
call :CompileShader%1 SkinnedEffect vs VSSkinnedVertexLightingTwoBones
call :CompileShader%1 SkinnedEffect vs VSSkinnedVertexLightingTwoBonesBn
call :CompileShader%1 SkinnedEffect vs VSSkinnedVertexLightingFourBones
call :CompileShader%1 SkinnedEffect vs VSSkinnedVertexLightingFourBonesBn

call :CompileShader%1 SkinnedEffect vs VSSkinnedOneLightOneBone
call :CompileShader%1 SkinnedEffect vs VSSkinnedOneLightOneBoneBn
call :CompileShader%1 SkinnedEffect vs VSSkinnedOneLightTwoBones
call :CompileShader%1 SkinnedEffect vs VSSkinnedOneLightTwoBonesBn
call :CompileShader%1 SkinnedEffect vs VSSkinnedOneLightFourBones
call :CompileShader%1 SkinnedEffect vs VSSkinnedOneLightFourBonesBn

call :CompileShader%1 SkinnedEffect vs VSSkinnedPixelLightingOneBone
call :CompileShader%1 SkinnedEffect vs VSSkinnedPixelLightingOneBoneBn
call :CompileShader%1 SkinnedEffect vs VSSkinnedPixelLightingTwoBones
call :CompileShader%1 SkinnedEffect vs VSSkinnedPixelLightingTwoBonesBn
call :CompileShader%1 SkinnedEffect vs VSSkinnedPixelLightingFourBones
call :CompileShader%1 SkinnedEffect vs VSSkinnedPixelLightingFourBonesBn

call :CompileShader%1 SkinnedEffect ps PSSkinnedVertexLighting
call :CompileShader%1 SkinnedEffect ps PSSkinnedVertexLightingNoFog
call :CompileShader%1 SkinnedEffect ps PSSkinnedPixelLighting

call :CompileShader%1 NormalMapEffect vs VSNormalPixelLightingTx
call :CompileShader%1 NormalMapEffect vs VSNormalPixelLightingTxBn
call :CompileShader%1 NormalMapEffect vs VSNormalPixelLightingTxVc
call :CompileShader%1 NormalMapEffect vs VSNormalPixelLightingTxVcBn

call :CompileShader%1 NormalMapEffect ps PSNormalPixelLightingTx
call :CompileShader%1 NormalMapEffect ps PSNormalPixelLightingTxNoFog
call :CompileShader%1 NormalMapEffect ps PSNormalPixelLightingTxNoSpec
call :CompileShader%1 NormalMapEffect ps PSNormalPixelLightingTxNoFogSpec

rem Must use DirectX Level 5_0 and above shaders for Holographic Render Target Arrays Support
call :CompileShader5_0%1 SpriteEffect vs SpriteVertexShader
call :CompileShader5_0%1 SpriteEffect vs NonVPRT_SpriteVertexShader
call :CompileShader5_0%1 SpriteEffect ps SpritePixelShader
call :CompileShaderHLSL5_0%1 PassThruGeometryShader gs SpriteGeometryShader


call :CompileShader%1 DGSLEffect vs main
call :CompileShader%1 DGSLEffect vs mainVc
call :CompileShader%1 DGSLEffect vs main1Bones
call :CompileShader%1 DGSLEffect vs main1BonesVc
call :CompileShader%1 DGSLEffect vs main2Bones
call :CompileShader%1 DGSLEffect vs main2BonesVc
call :CompileShader%1 DGSLEffect vs main4Bones
call :CompileShader%1 DGSLEffect vs main4BonesVc

call :CompileShaderHLSL%1 DGSLUnlit ps main
call :CompileShaderHLSL%1 DGSLLambert ps main
call :CompileShaderHLSL%1 DGSLPhong ps main

call :CompileShaderHLSL%1 DGSLUnlit ps mainTk
call :CompileShaderHLSL%1 DGSLLambert ps mainTk
call :CompileShaderHLSL%1 DGSLPhong ps mainTk

call :CompileShaderHLSL%1 DGSLUnlit ps mainTx
call :CompileShaderHLSL%1 DGSLLambert ps mainTx
call :CompileShaderHLSL%1 DGSLPhong ps mainTx

call :CompileShaderHLSL%1 DGSLUnlit ps mainTxTk
call :CompileShaderHLSL%1 DGSLLambert ps mainTxTk
call :CompileShaderHLSL%1 DGSLPhong ps mainTxTk
echo.

if %error% == 0 (
    echo Shaders compiled ok
) else (
    echo There were shader compilation errors!
)

endlocal
exit /b

:CompileShader
set fxc=fxc /nologo %1.fx /T%2_4_0_level_9_1 /Zi /Zpc /Qstrip_reflect /Qstrip_debug /E%3 /FhCompiled\%1_%3.inc /FdCompiled\%1_%3.pdb /Vn%1_%3
echo.
echo %fxc%
%fxc% || set error=1
exit /b

rem added section for Invoking fxc.exe using the DirectX Level 5_0
:CompileShader5_0
set fxc=fxc /nologo %1.fx /T%2_5_0 /Zi /Zpc /Qstrip_reflect /Qstrip_debug /E%3 /FhCompiled\%1_%3.inc /FdCompiled\%1_%3.pdb /Vn%1_%3
echo.
echo %fxc%
%fxc% || set error=1
exit /b

:CompileShaderHLSL5_0
set fxc=fxc /nologo %1.hlsl /T%2_5_0 /Zi /Zpc /Qstrip_reflect /Qstrip_debug /E%3 /FhCompiled\%1_%3.inc /FdCompiled\%1_%3.pdb /Vn%1_%3
echo.
echo %fxc%
%fxc% || set error=1
exit /b

:CompileShaderHLSL
set fxc=fxc /nologo %1.hlsl /T%2_4_0_level_9_1 /Zi /Zpc /Qstrip_reflect /Qstrip_debug /E%3 /FhCompiled\%1_%3.inc /FdCompiled\%1_%3.pdb /Vn%1_%3
echo.
echo %fxc%
%fxc% || set error=1
exit /b

:CompileShaderxbox
set fxc=%XBOXFXC% /nologo %1.fx /T%2_5_0 /Zpc /Zi /Qstrip_reflect /Qstrip_debug /D__XBOX_DISABLE_SHADER_NAME_EMPLACEMENT /E%3 /FhCompiled\XboxOne%1_%3.inc /FdCompiled\XboxOne%1_%3.pdb /Vn%1_%3
echo.
echo %fxc%
%fxc% || set error=1
exit /b

:CompileShaderHLSLxbox
set fxc=%XBOXFXC% /nologo %1.hlsl /T%2_5_0 /Zpc /Zi /Qstrip_reflect /Qstrip_debug /D__XBOX_DISABLE_SHADER_NAME_EMPLACEMENT /E%3 /FhCompiled\XboxOne%1_%3.inc /FdCompiled\XboxOne%1_%3.pdb /Vn%1_%3
echo.
echo %fxc%
%fxc% || set error=1
exit /b

:needxdk
echo ERROR: CompileShaders xbox requires the Microsoft Xbox One XDK
echo        (try re-running from the XDK Command Prompt)