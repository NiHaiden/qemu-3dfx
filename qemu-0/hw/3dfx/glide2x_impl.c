/*
 * QEMU 3Dfx Glide Pass-Through
 *
 *  Copyright (c) 2018-2020
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library;
 * if not, see <http://www.gnu.org/licenses/>.
 */

#include "qemu/osdep.h"
#include "hw/hw.h"

#include "glide2x_impl.h"

#define DEBUG_GLIDE2X

#ifdef DEBUG_GLIDE2X
#define DPRINTF(fmt, ...) \
    do { fprintf(stderr, "wr2x_trace: " fmt "\n", ## __VA_ARGS__); } while(0)
#else
#define DPRINTF(fmt, ...)
#endif

#if (defined(CONFIG_LINUX) && CONFIG_LINUX) || \
    (defined(CONFIG_DARWIN) && CONFIG_DARWIN)
#include <dlfcn.h>
  #if (defined(HOST_X86_64) && HOST_X86_64) || \
      (defined(HOST_AARCH64) && HOST_AARCH64)
  #define __stdcall
  #endif
#endif

struct tblFuncs {
    const char *sym;
    int impl;
    void *ptr;
};

static struct tblFuncs tblGlide2x[] = {


    /* Start - generated by mksymtbl */

  {.sym = "_ConvertAndDownloadRle@64", .impl = 0, .ptr = 0 },
  {.sym = "_grAADrawLine@8", .impl = 0, .ptr = 0 },
  {.sym = "_grAADrawPoint@4", .impl = 0, .ptr = 0 },
  {.sym = "_grAADrawPolygon@12", .impl = 0, .ptr = 0 },
  {.sym = "_grAADrawPolygonVertexList@8", .impl = 0, .ptr = 0 },
  {.sym = "_grAADrawTriangle@24", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaBlendFunction@16", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaCombine@20", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaControlsITRGBLighting@4", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaTestFunction@4", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaTestReferenceValue@4", .impl = 0, .ptr = 0 },
  {.sym = "_grBufferClear@12", .impl = 0, .ptr = 0 },
  {.sym = "_grBufferNumPending@0", .impl = 0, .ptr = 0 },
  {.sym = "_grBufferSwap@4", .impl = 0, .ptr = 0 },
  {.sym = "_grCheckForRoom@4", .impl = 0, .ptr = 0 },
  {.sym = "_grChromakeyMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grChromakeyValue@4", .impl = 0, .ptr = 0 },
  {.sym = "_grClipWindow@16", .impl = 0, .ptr = 0 },
  {.sym = "_grColorCombine@20", .impl = 0, .ptr = 0 },
  {.sym = "_grColorMask@8", .impl = 0, .ptr = 0 },
  {.sym = "_grConstantColorValue4@16", .impl = 0, .ptr = 0 },
  {.sym = "_grConstantColorValue@4", .impl = 0, .ptr = 0 },
  {.sym = "_grCullMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDepthBiasLevel@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDepthBufferFunction@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDepthBufferMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDepthMask@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDisableAllEffects@0", .impl = 0, .ptr = 0 },
  {.sym = "_grDitherMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawLine@8", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawPlanarPolygon@12", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawPlanarPolygonVertexList@8", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawPoint@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawPolygon@12", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawPolygonVertexList@8", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawTriangle@12", .impl = 0, .ptr = 0 },
  {.sym = "_grErrorSetCallback@4", .impl = 0, .ptr = 0 },
  {.sym = "_grFogColorValue@4", .impl = 0, .ptr = 0 },
  {.sym = "_grFogMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grFogTable@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGammaCorrectionValue@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideGetState@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideGetVersion@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideInit@0", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideSetState@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideShamelessPlug@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideShutdown@0", .impl = 0, .ptr = 0 },
  {.sym = "_grHints@8", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbConstantAlpha@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbConstantDepth@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbLock@24", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbReadRegion@28", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbUnlock@8", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbWriteColorFormat@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbWriteColorSwizzle@8", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbWriteRegion@32", .impl = 0, .ptr = 0 },
  {.sym = "_grRenderBuffer@4", .impl = 0, .ptr = 0 },
  {.sym = "_grResetTriStats@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSplash@20", .impl = 0, .ptr = 0 },
  {.sym = "_grSstConfigPipeline@12", .impl = 0, .ptr = 0 },
  {.sym = "_grSstControl@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstIdle@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstIsBusy@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstOrigin@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstPerfStats@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstQueryBoards@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstQueryHardware@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstResetPerfStats@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstScreenHeight@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstScreenWidth@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstSelect@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstStatus@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstVRetraceOn@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstVidMode@8", .impl = 0, .ptr = 0 },
  {.sym = "_grSstVideoLine@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstWinClose@0", .impl = 0, .ptr = 0 },
  {.sym = "_grSstWinOpen@28", .impl = 0, .ptr = 0 },
  {.sym = "_grTexCalcMemRequired@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTexClampMode@12", .impl = 0, .ptr = 0 },
  {.sym = "_grTexCombine@28", .impl = 0, .ptr = 0 },
  {.sym = "_grTexCombineFunction@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDetailControl@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadMipMap@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadMipMapLevel@32", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadMipMapLevelPartial@40", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadTable@12", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadTablePartial@20", .impl = 0, .ptr = 0 },
  {.sym = "_grTexFilterMode@12", .impl = 0, .ptr = 0 },
  {.sym = "_grTexLodBiasValue@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTexMaxAddress@4", .impl = 0, .ptr = 0 },
  {.sym = "_grTexMinAddress@4", .impl = 0, .ptr = 0 },
  {.sym = "_grTexMipMapMode@12", .impl = 0, .ptr = 0 },
  {.sym = "_grTexMultibase@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTexMultibaseAddress@20", .impl = 0, .ptr = 0 },
  {.sym = "_grTexNCCTable@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTexSource@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTexTextureMemRequired@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTriStats@8", .impl = 0, .ptr = 0 },
  {.sym = "_gu3dfGetInfo@8", .impl = 0, .ptr = 0 },
  {.sym = "_gu3dfLoad@8", .impl = 0, .ptr = 0 },
  {.sym = "_guAADrawTriangleWithClip@12", .impl = 0, .ptr = 0 },
  {.sym = "_guAlphaSource@4", .impl = 0, .ptr = 0 },
  {.sym = "_guColorCombineFunction@4", .impl = 0, .ptr = 0 },
  {.sym = "_guDrawPolygonVertexListWithClip@8", .impl = 0, .ptr = 0 },
  {.sym = "_guDrawTriangleWithClip@12", .impl = 0, .ptr = 0 },
  {.sym = "_guEncodeRLE16@16", .impl = 0, .ptr = 0 },
  {.sym = "_guEndianSwapBytes@4", .impl = 0, .ptr = 0 },
  {.sym = "_guEndianSwapWords@4", .impl = 0, .ptr = 0 },
  {.sym = "_guFogGenerateExp2@8", .impl = 0, .ptr = 0 },
  {.sym = "_guFogGenerateExp@8", .impl = 0, .ptr = 0 },
  {.sym = "_guFogGenerateLinear@12", .impl = 0, .ptr = 0 },
  {.sym = "_guFogTableIndexToW@4", .impl = 0, .ptr = 0 },
  {.sym = "_guMPDrawTriangle@12", .impl = 0, .ptr = 0 },
  {.sym = "_guMPInit@0", .impl = 0, .ptr = 0 },
  {.sym = "_guMPTexCombineFunction@4", .impl = 0, .ptr = 0 },
  {.sym = "_guMPTexSource@8", .impl = 0, .ptr = 0 },
  {.sym = "_guMovieSetName@4", .impl = 0, .ptr = 0 },
  {.sym = "_guMovieStart@0", .impl = 0, .ptr = 0 },
  {.sym = "_guMovieStop@0", .impl = 0, .ptr = 0 },
  {.sym = "_guTexAllocateMemory@60", .impl = 0, .ptr = 0 },
  {.sym = "_guTexChangeAttributes@48", .impl = 0, .ptr = 0 },
  {.sym = "_guTexCombineFunction@8", .impl = 0, .ptr = 0 },
  {.sym = "_guTexCreateColorMipMap@0", .impl = 0, .ptr = 0 },
  {.sym = "_guTexDownloadMipMap@12", .impl = 0, .ptr = 0 },
  {.sym = "_guTexDownloadMipMapLevel@12", .impl = 0, .ptr = 0 },
  {.sym = "_guTexGetCurrentMipMap@4", .impl = 0, .ptr = 0 },
  {.sym = "_guTexGetMipMapInfo@4", .impl = 0, .ptr = 0 },
  {.sym = "_guTexMemQueryAvail@4", .impl = 0, .ptr = 0 },
  {.sym = "_guTexMemReset@0", .impl = 0, .ptr = 0 },
  {.sym = "_guTexSource@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbBegin@0", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbBypassMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbEnd@0", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbGetReadPtr@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbGetWritePtr@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbOrigin@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbWriteMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstOpen@24", .impl = 0, .ptr = 0 },
  {.sym = "_grSstPassthruMode@4", .impl = 0, .ptr = 0 },
  {.sym = "_guFbReadRegion@24", .impl = 0, .ptr = 0 },
  {.sym = "_guFbWriteRegion@24", .impl = 0, .ptr = 0 },
  {.sym = "_grSplash@0", .impl = 0, .ptr = 0 },
  {.sym = "_grCoordinateSpace@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDepthRange@8", .impl = 0, .ptr = 0 },
  {.sym = "_grDisable@4", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawVertexArray@12", .impl = 0, .ptr = 0 },
  {.sym = "_grDrawVertexArrayContiguous@16", .impl = 0, .ptr = 0 },
  {.sym = "_grEnable@4", .impl = 0, .ptr = 0 },
  {.sym = "_grFinish@0", .impl = 0, .ptr = 0 },
  {.sym = "_grFlush@0", .impl = 0, .ptr = 0 },
  {.sym = "_grGet@12", .impl = 0, .ptr = 0 },
  {.sym = "_grGetProcAddress@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGetString@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideGetVertexLayout@4", .impl = 0, .ptr = 0 },
  {.sym = "_grGlideSetVertexLayout@4", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbWriteRegion@36", .impl = 0, .ptr = 0 },
  {.sym = "_grLoadGammaTable@16", .impl = 0, .ptr = 0 },
  {.sym = "_grQueryResolutions@8", .impl = 0, .ptr = 0 },
  {.sym = "_grReset@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSelectContext@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstWinClose@4", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadTable@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTexDownloadTablePartial@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTexNCCTable@4", .impl = 0, .ptr = 0 },
  {.sym = "_grVertexLayout@12", .impl = 0, .ptr = 0 },
  {.sym = "_grViewport@16", .impl = 0, .ptr = 0 },
  {.sym = "_guGammaCorrectionRGB@12", .impl = 0, .ptr = 0 },
  /* ---- g3ext ---- */
  {.sym = "_grGetGammaTableExt@16", .impl = 0, .ptr = 0 },
  {.sym = "_grChromaRangeModeExt@4", .impl = 0, .ptr = 0 },
  {.sym = "_grChromaRangeExt@12", .impl = 0, .ptr = 0 },
  {.sym = "_grTexChromaModeExt@8", .impl = 0, .ptr = 0 },
  {.sym = "_grTexChromaRangeExt@16", .impl = 0, .ptr = 0 },
  {.sym = "_grColorCombineExt@40", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaCombineExt@40", .impl = 0, .ptr = 0 },
  {.sym = "_grTexColorCombineExt@44", .impl = 0, .ptr = 0 },
  {.sym = "_grTexAlphaCombineExt@44", .impl = 0, .ptr = 0 },
  {.sym = "_grAlphaBlendFunctionExt@24", .impl = 0, .ptr = 0 },
  {.sym = "_grConstantColorValueExt@8", .impl = 0, .ptr = 0 },
  {.sym = "_grColorMaskExt@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTBufferWriteMaskExt@4", .impl = 0, .ptr = 0 },
  {.sym = "_grBufferClearExt@16", .impl = 0, .ptr = 0 },
  {.sym = "_grTextureBufferExt@28", .impl = 0, .ptr = 0 },
  {.sym = "_grTextureAuxBufferExt@28", .impl = 0, .ptr = 0 },
  {.sym = "_grAuxBufferExt@4", .impl = 0, .ptr = 0 },
  {.sym = "_grStencilFuncExt@12", .impl = 0, .ptr = 0 },
  {.sym = "_grStencilMaskExt@4", .impl = 0, .ptr = 0 },
  {.sym = "_grStencilOpExt@12", .impl = 0, .ptr = 0 },
  {.sym = "_grLfbConstantStencilExt@4", .impl = 0, .ptr = 0 },
  {.sym = "_grSstWinOpenExt@32", .impl = 0, .ptr = 0 },


    /* End - generated by mksymtbl */
};

static int getNumArgs(const char *sym)
{
    char *p = (char *)sym;
    while (*p != '@') p++;
    return (atoi(++p) >> 2);
}

int GRFEnumArgsCnt(int FEnum)
{
    int val = getNumArgs(tblGlide2x[FEnum].sym);

    switch (FEnum) {
        case FEnum_grTexDownloadMipMap:
        case FEnum_grTexDownloadMipMapLevel:
        case FEnum_grTexDownloadMipMapLevelPartial:
        case FEnum_guTexDownloadMipMap:
        case FEnum_guTexDownloadMipMapLevel:
            val++;
            break;
    }

    return val;
}

uint32_t texTableValid(uint32_t format) {
    switch (format) {
        case GR_TEXFMT_YIQ_422:
        case GR_TEXFMT_AYIQ_8422:
        case GR_TEXFMT_P_8:
        case GR_TEXFMT_AP_88:
            return 1;
    }

    return 0;
}

uint32_t wrReadRegion(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uintptr_t arg6)
{
    uint32_t __stdcall (*fpra5p6)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uintptr_t arg6);
    fpra5p6 = tblGlide2x[FEnum_grLfbReadRegion].ptr;
    return (*fpra5p6)(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

uint32_t wrWriteRegion(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uintptr_t arg7)
{
    uint32_t __stdcall (*fpra6p7)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uintptr_t arg7);
    fpra6p7 = tblGlide2x[FEnum_grLfbWriteRegion].ptr;
    return (*fpra6p7)(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

uintptr_t wrGetProcAddress(uintptr_t a0)
{
    uintptr_t __stdcall (*fprp0)(uintptr_t arg0);
    fprp0 = tblGlide2x[FEnum_grGetProcAddress].ptr;
    return (*fprp0)(a0);
}

const char *wrGetString(uint32_t a0)
{
    const char * __stdcall (*fpra0)(uint32_t arg0);
    fpra0 = tblGlide2x[FEnum_grGetString].ptr;
    return (*fpra0)(a0);
}

const char *getGRFuncStr(int FEnum)
{
    if (tblGlide2x[FEnum].impl == 0) {
        tblGlide2x[FEnum].impl = GRFuncTrace()? (2 - GRFuncTrace()):1;
        return tblGlide2x[FEnum].sym;
    }
    return 0;
}

void doGlideFunc(int FEnum, uint32_t *arg, uintptr_t *parg, uintptr_t *ret, int emu211)
{
    static int glidePostInit = 0;
    int numArgs = getNumArgs(tblGlide2x[FEnum].sym);

    if (GRFuncTrace()) {
        const char *fstr = getGRFuncStr(FEnum);
        if (fstr)
            DPRINTF("%-64s", fstr);
    }

    if (glidePostInit == 0) {
	switch (FEnum) {
	    case FEnum_grGet:
	    case FEnum_grGlideGetVersion:
	    case FEnum_grGlideInit:
	    case FEnum_grSstControl:
	    case FEnum_grSstQueryBoards:
	    case FEnum_grSstQueryHardware:
	    case FEnum_grSstSelect:
		fprintf(stderr, "trace: %s called\n", tblGlide2x[FEnum].sym);
		if (FEnum == FEnum_grGlideInit)
		    glidePostInit = 1;
		break;
	    default:
		fprintf(stderr, "WARN: Illegal %s call blocked\n", tblGlide2x[FEnum].sym);
		*ret = 0;
		return;
	}
    }
    if (FEnum == FEnum_grGlideShutdown)
	glidePostInit = 0;

    switch (FEnum) {
	case FEnum_grLfbBegin:
	case FEnum_grLfbEnd:
	case FEnum_grLfbOrigin:
	case FEnum_grLfbWriteMode:
	case FEnum_grLfbBypassMode:
	case FEnum_grLfbGetReadPtr:
	case FEnum_grLfbGetWritePtr:
	case FEnum_grSstPassthruMode:
	case FEnum_grSplash0:
	    if (emu211) {
		numArgs = -1;
                break;
            }
            /* fall through */
        default:
            if (tblGlide2x[FEnum].ptr == 0) {
                fprintf(stderr, "WARN: %s nullptr call blocked\n", tblGlide2x[FEnum].sym);
                *ret = 0;
                return;
            }
            break;
    }

    typedef union {
    uint32_t __stdcall (*fprp0)(uintptr_t arg0);
    uint32_t __stdcall (*fprp1)(uintptr_t arg0, uintptr_t arg1);
    uint32_t __stdcall (*fpra0p1)(uint32_t arg0, uintptr_t arg1);
    uint32_t __stdcall (*fpra0p2)(uint32_t arg0, uintptr_t arg1, uintptr_t arg2);
    uint32_t __stdcall (*fpra1p2)(uint32_t arg0, uint32_t arg1, uintptr_t arg2);
    uint32_t __stdcall (*fprp2)(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2);
    uint32_t __stdcall (*fpra0p3)(uint32_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3);
    uint32_t __stdcall (*fpra0p1a3)(uint32_t arg0, uintptr_t arg1, uint32_t arg2, uint32_t arg3);
    uint32_t __stdcall (*fprp2a5)(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5);
    uint32_t __stdcall (*fpra1p2a3)(uint32_t arg0, uint32_t arg1, uintptr_t arg2, uint32_t arg3);
    uint32_t __stdcall (*fpra1p2a4)(uint32_t arg0, uint32_t arg1, uintptr_t arg2, uint32_t arg3, uint32_t arg4);
    uint32_t __stdcall (*fpra2p3)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uintptr_t arg3);
    uint32_t __stdcall (*fpra3p4a5)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uintptr_t arg4, uint32_t arg5);
    uint32_t __stdcall (*fpra4p5)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uintptr_t arg5);
    uint32_t __stdcall (*fpra5p6)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uintptr_t arg6);
    uint32_t __stdcall (*fpra6p7)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uintptr_t arg7);
    uint32_t __stdcall (*fpra7p8)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uintptr_t arg8);
    uint32_t __stdcall (*fpra6p7a9)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uintptr_t arg7, uint32_t arg8, uint32_t arg9);
    /* GLIDE APIs with float */
    float __stdcall (*fprfra0)(uint32_t arg0);
    uint32_t __stdcall (*fprp0f1)(uintptr_t arg0, float arg1);
    uint32_t __stdcall (*fprp0f2)(uintptr_t arg0, float arg1, float arg2);
    uint32_t __stdcall (*fprf0)(float arg0);
    uint32_t __stdcall (*fprf1)(float arg0, float arg1);
    uint32_t __stdcall (*fpra0f1)(uint32_t arg0, float arg1);
    uint32_t __stdcall (*fpra2f3)(uint32_t arg0, uint32_t arg1, uint32_t arg2, float arg3);
    uint32_t __stdcall (*fprf2)(float arg0, float arg1, float arg2);
    uint32_t __stdcall (*fprf3)(float arg0, float arg1, float arg2, float arg3);
    uint32_t __stdcall (*fprf3a4)(float arg0, float arg1, float arg2, float arg3, uint32_t arg4);
    uint32_t __stdcall (*fpra12f13a14)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10, uint32_t arg11, uint32_t arg12, float arg13, uint32_t arg14);
    } PARG_FP;
    PARG_FP sfp;

    switch (FEnum) {
	case FEnum_grDrawPoint:
	case FEnum_grAADrawPoint:
        case FEnum_grGlideSetState:
        case FEnum_grGlideGetState:
        case FEnum_grGlideGetVersion:
	case FEnum_grGlideSetVertexLayout:
	case FEnum_grGlideGetVertexLayout:
        case FEnum_grSstPerfStats:
        case FEnum_grSstQueryHardware:
	case FEnum_grSstQueryBoards:
	case FEnum_grFogTable:
            sfp.fprp0 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fprp0))(parg[0]);
            numArgs = -1;
            break;
        case FEnum_grSstOpen:
        case FEnum_grSstWinClose3x:
        case FEnum_grSstWinClose:
        case FEnum_grSstWinOpen:
        case FEnum_grSstWinOpenExt:
            *ret = 1;
            numArgs = -1;
            break;
	case FEnum_grDrawLine:
	case FEnum_grAADrawLine:
	case FEnum_grTriStats:
	case FEnum_gu3dfGetInfo:
	case FEnum_gu3dfLoad:
	case FEnum_grQueryResolutions:
            sfp.fprp1 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fprp1))(parg[0], parg[1]);
            numArgs = -1;
            break;
	case FEnum_grTexTextureMemRequired:
	case FEnum_grDrawPolygonVertexList:
	case FEnum_grAADrawPolygonVertexList:
	case FEnum_grDrawPlanarPolygonVertexList:
	case FEnum_guDrawPolygonVertexListWithClip:
        case FEnum_grTexDownloadTable3x:
            sfp.fpra0p1 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra0p1))(arg[0], parg[1]);
            numArgs = -1;
            break;
        case FEnum_grDrawTriangle:
	case FEnum_guDrawTriangleWithClip:
	case FEnum_guAADrawTriangleWithClip:
            sfp.fprp2 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fprp2))(parg[0], parg[1], parg[2]);
            numArgs = -1;
            break;
        case FEnum_grLoadGammaTable:
        case FEnum_grGetGammaTableExt:
            sfp.fpra0p3 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra0p3))(arg[0], parg[1], parg[2], parg[3]);
            numArgs = -1;
            break;
	case FEnum_grAADrawTriangle:
	    sfp.fprp2a5 = tblGlide2x[FEnum].ptr;
	    *ret = (*(sfp.fprp2a5))(parg[0], parg[1],parg[2], arg[3], arg[4], arg[5]);
	    numArgs = -1;
	    break;
        case FEnum_grTexSource:
        case FEnum_grTexDownloadMipMap:
            sfp.fpra2p3 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra2p3))(arg[0], arg[1], arg[2], parg[3]);
            numArgs = -1;
            break;
	case FEnum_grTexDownloadTable:
	case FEnum_grGet:
        case FEnum_grDrawVertexArray:
        case FEnum_guTexDownloadMipMapLevel:
            sfp.fpra1p2 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra1p2))(arg[0], arg[1], parg[2]);
            numArgs = -1;
            break;
        case FEnum_grDrawVertexArrayContiguous:
            sfp.fpra1p2a3 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra1p2a3))(arg[0], arg[1], parg[2], arg[3]);
            numArgs = -1;
            break;
	case FEnum_grTexDownloadTablePartial:
            sfp.fpra1p2a4 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra1p2a4))(arg[0], arg[1], parg[2], arg[3], arg[4]);
            numArgs = -1;
            break;
	case FEnum_grTexDownloadTablePartial3x:
            sfp.fpra0p1a3 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra0p1a3))(arg[0], parg[1], arg[2], arg[3]);
            numArgs = -1;
            break;
	case FEnum_guFbReadRegion:
	case FEnum_guFbWriteRegion:
	    sfp.fpra3p4a5 = tblGlide2x[FEnum].ptr;
	    *ret = (*(sfp.fpra3p4a5))(arg[0], arg[1], arg[2], arg[3], parg[0], arg[5]);
	    break;
        case FEnum_grLfbLock:
            if (arg[1] & 0x80U) {
                arg[1] &= 0x0FU;
                *ret = 1;
            }
            else {
                sfp.fpra4p5 = tblGlide2x[FEnum].ptr;
                *ret = (*(sfp.fpra4p5))(arg[0], arg[1], arg[2], arg[3], arg[4], parg[1]);
            }
            numArgs = -1;
            break;
        case FEnum_grLfbUnlock:
            if (arg[1] & 0x80U) {
                arg[1] &= 0x0FU;
                *ret = 1;
                numArgs = -1;
            }
            break;
        case FEnum_grLfbReadRegion:
            sfp.fpra5p6 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra5p6))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], parg[2]);
            numArgs = -1;
            break;
        case FEnum_grLfbWriteRegion:
	case FEnum_grTexDownloadMipMapLevel:
            sfp.fpra6p7 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra6p7))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], parg[3]);
            numArgs = -1;
            break;
        case FEnum_grLfbWriteRegion3x:
            sfp.fpra7p8 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra7p8))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], parg[0]);
            numArgs = -1;
            break;
        case FEnum_grTexDownloadMipMapLevelPartial:
            sfp.fpra6p7a9 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra6p7a9))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], parg[3], arg[8], arg[9]);
            numArgs = -1;
            break;
        case FEnum_guTexDownloadMipMap:
	case FEnum_grDrawPolygon:
	case FEnum_grAADrawPolygon:
	case FEnum_grDrawPlanarPolygon:
            sfp.fpra0p2 = tblGlide2x[FEnum].ptr;
            *ret = (*(sfp.fpra0p2))(arg[0], parg[1], parg[2]);
            numArgs = -1;
            break;

	/* GLIDE APIs with float */
	case FEnum_guFogTableIndexToW:
	    {
		float r;
		sfp.fprfra0 = tblGlide2x[FEnum].ptr;
		r = (*(sfp.fprfra0))(arg[0]);
		memcpy(ret, &r, sizeof(uint32_t));
	    }
	    numArgs = -1;
	    break;
	case FEnum_guFogGenerateExp:
	case FEnum_guFogGenerateExp2:
	    {
		float a1;
		memcpy(&a1, &arg[1], sizeof(uint32_t));
		sfp.fprp0f1 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fprp0f1))(parg[0], a1);
	    }
            numArgs = -1;
            break;
	case FEnum_guFogGenerateLinear:
	    {
		float a1, a2;
		memcpy(&a1, &arg[1], sizeof(uint32_t));
		memcpy(&a2, &arg[2], sizeof(uint32_t));
		sfp.fprp0f2 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fprp0f2))(parg[0], a1, a2);
	    }
	    numArgs = -1;
	    break;
	case FEnum_grGammaCorrectionValue:
	    {
		float a0;
		memcpy(&a0, &arg[0], sizeof(uint32_t));
		sfp.fprf0 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fprf0))(a0);
	    }
	    numArgs = -1;
	    break;
        case FEnum_grDepthRange:
            {
                float a0, a1;
                memcpy(&a0, &arg[0], sizeof(uint32_t));
                memcpy(&a1, &arg[1], sizeof(uint32_t));
                sfp.fprf1 = tblGlide2x[FEnum].ptr;
                *ret = (*(sfp.fprf1))(a0, a1);
                numArgs = -1;
            }
            break;
	case FEnum_grTexLodBiasValue:
	    {
		float a1;
		memcpy(&a1, &arg[1], sizeof(uint32_t));
		sfp.fpra0f1 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fpra0f1))(arg[0], a1);
	    }
	    numArgs = -1;
	    break;
	case FEnum_grTexDetailControl:
	    {
		float a3;
		memcpy(&a3, &arg[3], sizeof(uint32_t));
		sfp.fpra2f3 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fpra2f3))(arg[0], arg[1], arg[2], a3);
	    }
	    numArgs = -1;
	    break;
	case FEnum_guGammaCorrectionRGB:
	    {
		float a0, a1, a2;
		memcpy(&a0, &arg[0], sizeof(uint32_t));
		memcpy(&a1, &arg[1], sizeof(uint32_t));
		memcpy(&a2, &arg[2], sizeof(uint32_t));
		sfp.fprf2 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fprf2))(a0, a1, a2);
	    }
	    numArgs = -1;
	    break;
	case FEnum_grConstantColorValue4:
	    {
		float a0, a1, a2, a3;
		memcpy(&a0, &arg[0], sizeof(uint32_t));
		memcpy(&a1, &arg[1], sizeof(uint32_t));
		memcpy(&a2, &arg[2], sizeof(uint32_t));
		memcpy(&a3, &arg[3], sizeof(uint32_t));
		sfp.fprf3 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fprf3))(a0, a1, a2, a3);
	    }
	    numArgs = -1;
	    break;
	case FEnum_grSplash:
	    {
		float a0, a1, a2, a3;
		memcpy(&a0, &arg[0], sizeof(uint32_t));
		memcpy(&a1, &arg[1], sizeof(uint32_t));
		memcpy(&a2, &arg[2], sizeof(uint32_t));
		memcpy(&a3, &arg[3], sizeof(uint32_t));
		sfp.fprf3a4 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fprf3a4))(a0, a1, a2, a3, arg[4]);
	    }
	    numArgs = -1;
	    break;
	case FEnum_guTexAllocateMemory:
	    {
		float a13;
		memcpy(&a13, &arg[13], sizeof(uint32_t));
		sfp.fpra12f13a14 = tblGlide2x[FEnum].ptr;
		*ret = (*(sfp.fpra12f13a14))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10], arg[11], arg[12], a13, arg[14]);
	    }
	    numArgs = -1;
	    break;

    }



    /* Start - generated by hostgenfuncs */

    typedef union {
    uint32_t __stdcall (*fpra0)(void);
    uint32_t __stdcall (*fpra1)(uint32_t arg0);
    uint32_t __stdcall (*fpra2)(uint32_t arg0, uint32_t arg1);
    uint32_t __stdcall (*fpra3)(uint32_t arg0, uint32_t arg1, uint32_t arg2);
    uint32_t __stdcall (*fpra4)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3);
    uint32_t __stdcall (*fpra5)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);
    uint32_t __stdcall (*fpra6)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5);
    uint32_t __stdcall (*fpra7)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6);
    uint32_t __stdcall (*fpra8)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7);
    uint32_t __stdcall (*fpra9)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8);
    uint32_t __stdcall (*fpra10)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9);
    uint32_t __stdcall (*fpra11)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10);
    uint32_t __stdcall (*fpra12)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10, uint32_t arg11);
    uint32_t __stdcall (*fpra13)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10, uint32_t arg11, uint32_t arg12);
    uint32_t __stdcall (*fpra14)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10, uint32_t arg11, uint32_t arg12, uint32_t arg13);
    uint32_t __stdcall (*fpra15)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10, uint32_t arg11, uint32_t arg12, uint32_t arg13, uint32_t arg14);
    uint32_t __stdcall (*fpra16)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8, uint32_t arg9, uint32_t arg10, uint32_t arg11, uint32_t arg12, uint32_t arg13, uint32_t arg14, uint32_t arg15);
    } UARG_FP;
    UARG_FP ufp;

    switch (numArgs) {
    case 0:
	ufp.fpra0 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra0))();
	break;
    case 1:
	ufp.fpra1 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra1))(arg[0]);
	break;
    case 2:
	ufp.fpra2 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra2))(arg[0], arg[1]);
	break;
    case 3:
	ufp.fpra3 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra3))(arg[0], arg[1], arg[2]);
	break;
    case 4:
	ufp.fpra4 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra4))(arg[0], arg[1], arg[2], arg[3]);
	break;
    case 5:
	ufp.fpra5 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra5))(arg[0], arg[1], arg[2], arg[3], arg[4]);
	break;
    case 6:
	ufp.fpra6 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra6))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5]);
	break;
    case 7:
	ufp.fpra7 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra7))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);
	break;
    case 8:
	ufp.fpra8 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra8))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7]);
	break;
    case 9:
	ufp.fpra9 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra9))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8]);
	break;
    case 10:
	ufp.fpra10 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra10))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9]);
	break;
    case 11:
	ufp.fpra11 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra11))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10]);
	break;
    case 12:
	ufp.fpra12 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra12))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10], arg[11]);
	break;
    case 13:
	ufp.fpra13 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra13))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10], arg[11], arg[12]);
	break;
    case 14:
	ufp.fpra14 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra14))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10], arg[11], arg[12], arg[13]);
	break;
    case 15:
	ufp.fpra15 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra15))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10], arg[11], arg[12], arg[13], arg[14]);
	break;
    case 16:
	ufp.fpra16 = tblGlide2x[FEnum].ptr;
	*ret = (*(ufp.fpra16))(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7], arg[8], arg[9], arg[10], arg[11], arg[12], arg[13], arg[14], arg[15]);
	break;
    default:
	break;
    }

    /* End - generated by hostgenfuncs */

}

#if defined(CONFIG_WIN32) && CONFIG_WIN32
static HINSTANCE hDll = 0;
#endif
#if (defined(CONFIG_LINUX) && CONFIG_LINUX) || \
    (defined(CONFIG_DARWIN) && CONFIG_DARWIN)
static void *hDll = 0;
#endif
void __stdcall (*setConfig)(const uint32_t flag);
void __stdcall (*setConfigRes)(const int res);
void conf_glide2x(const uint32_t flags, const int res)
{
    if (setConfig)
        (*setConfig)(flags);
    if (res && setConfigRes)
        (*setConfigRes)(res);
}

void cwnd_glide2x(void *swnd, void *nwnd, void *opaque)
{
    union {
        uintptr_t (__stdcall *SstOpen)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
        uintptr_t (__stdcall *SstWinOpen)(uintptr_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
        uintptr_t (__stdcall *SstWinOpenExt)(uintptr_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
        void (__stdcall *SstWinClose)(void);
        void (__stdcall *SstWinClose3x)(uintptr_t arg0);
    } GrWndFunc;

#if defined(CONFIG_WIN32) && CONFIG_WIN32
    uintptr_t wnd = othr_hwnd()? (uintptr_t)swnd:(uintptr_t)nwnd;
#endif
#if (defined(CONFIG_LINUX) && CONFIG_LINUX) || \
    (defined(CONFIG_DARWIN) && CONFIG_DARWIN)
    uintptr_t wnd = othr_hwnd()? (uintptr_t)nwnd:(uintptr_t)swnd;
#endif
    window_cb *s = opaque;

    switch (s->FEnum) {
        case FEnum_grSstWinClose3x:
            GrWndFunc.SstWinClose3x = tblGlide2x[s->FEnum].ptr;
            GrWndFunc.SstWinClose3x(s->GrContext);
            break;
        case FEnum_grSstWinClose:
            GrWndFunc.SstWinClose = tblGlide2x[s->FEnum].ptr;
            GrWndFunc.SstWinClose();
            break;
        case FEnum_grSstOpen:
            GrWndFunc.SstOpen = tblGlide2x[s->FEnum].ptr;
            s->GrContext = GrWndFunc.SstOpen(s->arg[0], s->arg[1], s->arg[2], s->arg[3], s->arg[4], s->arg[5]);
            break;
        case FEnum_grSstWinOpen:
            GrWndFunc.SstWinOpen = tblGlide2x[s->FEnum].ptr;
            s->GrContext = GrWndFunc.SstWinOpen(wnd, s->arg[1], s->arg[2], s->arg[3], s->arg[4], s->arg[5], s->arg[6]);
            break;
        case FEnum_grSstWinOpenExt:
            GrWndFunc.SstWinOpenExt = tblGlide2x[s->FEnum].ptr;
            s->GrContext = GrWndFunc.SstWinOpenExt(wnd, s->arg[1], s->arg[2], s->arg[3], s->arg[4], s->arg[5], s->arg[6],s->arg[7]);
            break;
        default:
            if (!s->FEnum)
                fini_glide2x();
            break;
    }
}

void fini_glide2x(void)
{
    if (hDll) {
#if defined(CONFIG_WIN32) && CONFIG_WIN32
        FreeLibrary(hDll);
#endif
#if (defined(CONFIG_LINUX) && CONFIG_LINUX) || \
    (defined(CONFIG_DARWIN) && CONFIG_DARWIN)
	dlclose(hDll);
#endif
    }
    hDll = 0;
    for (int i = 0; i < FEnum_zzG2xFuncEnum_max; i++) {
        tblGlide2x[i].impl = 0;
	tblGlide2x[i].ptr = 0;
    }
}

int init_glide2x(const char *dllname)
{
    int i;
    
#if defined(CONFIG_WIN32) && CONFIG_WIN32
    hDll = LoadLibrary(dllname);
    if (!hDll) {
        char prefix[32] = "lib";
        const char *libname = strcat(prefix, dllname);
        hDll = LoadLibrary(libname);
    }
    setConfig = (void *)(GetProcAddress(hDll, "_setConfig@4"));
    setConfigRes = (void *)(GetProcAddress(hDll, "_setConfigRes@4"));
#endif
#if (defined(CONFIG_LINUX) && CONFIG_LINUX) || \
    (defined(CONFIG_DARWIN) && CONFIG_DARWIN)
    int enWrap3x = 0;
    if (!strncmp(dllname, "glide2x.dll", sizeof("glide2x.dll")))
#if defined(CONFIG_LINUX) && CONFIG_LINUX
        hDll = dlopen("libglide2x.so", RTLD_NOW);
#elif defined(CONFIG_DARWIN) && CONFIG_DARWIN
        hDll = dlopen("libglide2x.dylib", RTLD_NOW);
#else
#error Unknown dynamic load library
#endif
    if (!strncmp(dllname, "glide3x.dll", sizeof("glide3x.dll"))) {
#if defined(CONFIG_LINUX) && CONFIG_LINUX
        hDll = dlopen("libglide3x.so", RTLD_NOW);
#elif defined(CONFIG_DARWIN) && CONFIG_DARWIN
        hDll = dlopen("libglide3x.dylib", RTLD_NOW);
#else
#error Unknown dynamic load library
#endif
        enWrap3x = 1;
    }
    setConfig = (void *)(dlsym(hDll, "setConfig"));
    setConfigRes = (void *)(dlsym(hDll, "setConfigRes"));
#endif
    
    if (!hDll) {
        return 1;
    }

    for (i = 0; i < FEnum_zzG2xFuncEnum_max; i++) {
#if defined(CONFIG_WIN32) && CONFIG_WIN32
        tblGlide2x[i].ptr = (void *)(GetProcAddress(hDll, tblGlide2x[i].sym));
#endif
#if (defined(CONFIG_LINUX) && CONFIG_LINUX) || \
    (defined(CONFIG_DARWIN) && CONFIG_DARWIN)
	char lnxsym[128], wrapsym[128] = "wrap3x_", *pws = wrapsym;
	strncpy(lnxsym, tblGlide2x[i].sym + 1, sizeof(lnxsym)-1);
	for (int i = 0; i < sizeof(lnxsym); i++) {
	    if (lnxsym[i] == '@') {
		lnxsym[i] = 0;
		break;
	    }
	}
        pws = strcat(wrapsym, lnxsym);
        void *plf = dlsym(hDll, lnxsym), *pwf = dlsym(hDll, pws);
        tblGlide2x[i].ptr = (enWrap3x && pwf)? pwf:plf;
#endif
    }

    return 0;
}

int init_g3ext(void)
{
    tblGlide2x[FEnum_grGetGammaTableExt].ptr   = (void *)(wrGetProcAddress((uintptr_t)"grGetGammaTableExt"));
    tblGlide2x[FEnum_grChromaRangeModeExt].ptr = (void *)(wrGetProcAddress((uintptr_t)"grChromaRangeModeExt"));
    tblGlide2x[FEnum_grChromaRangeExt].ptr     = (void *)(wrGetProcAddress((uintptr_t)"grChromaRangeExt"));
    tblGlide2x[FEnum_grTexChromaModeExt].ptr   = (void *)(wrGetProcAddress((uintptr_t)"grTexChromaModeExt"));
    tblGlide2x[FEnum_grTexChromaRangeExt].ptr  = (void *)(wrGetProcAddress((uintptr_t)"grTexChromaRangeExt"));
    tblGlide2x[FEnum_grColorCombineExt].ptr    = (void *)(wrGetProcAddress((uintptr_t)"grColorCombineExt"));
    tblGlide2x[FEnum_grAlphaCombineExt].ptr    = (void *)(wrGetProcAddress((uintptr_t)"grAlphaCombineExt"));
    tblGlide2x[FEnum_grTexColorCombineExt].ptr = (void *)(wrGetProcAddress((uintptr_t)"grTexColorCombineExt"));
    tblGlide2x[FEnum_grTexAlphaCombineExt].ptr = (void *)(wrGetProcAddress((uintptr_t)"grTexAlphaCombineExt"));
    tblGlide2x[FEnum_grAlphaBlendFunctionExt].ptr = (void *)(wrGetProcAddress((uintptr_t)"grAlphaBlendFunctionExt"));
    tblGlide2x[FEnum_grConstantColorValueExt].ptr = (void *)(wrGetProcAddress((uintptr_t)"grConstantColorValueExt"));
    tblGlide2x[FEnum_grColorMaskExt].ptr       = (void *)(wrGetProcAddress((uintptr_t)"grColorMaskExt"));
    tblGlide2x[FEnum_grTBufferWriteMaskExt].ptr   = (void *)(wrGetProcAddress((uintptr_t)"grTBufferWriteMaskExt"));
    tblGlide2x[FEnum_grBufferClearExt].ptr     = (void *)(wrGetProcAddress((uintptr_t)"grBufferClearExt"));
    tblGlide2x[FEnum_grTextureBufferExt].ptr   = (void *)(wrGetProcAddress((uintptr_t)"grTextureBufferExt"));
    tblGlide2x[FEnum_grTextureAuxBufferExt].ptr   = (void *)(wrGetProcAddress((uintptr_t)"grTextureAuxBufferExt"));
    tblGlide2x[FEnum_grAuxBufferExt].ptr       = (void *)(wrGetProcAddress((uintptr_t)"grAuxBufferExt"));
    tblGlide2x[FEnum_grStencilFuncExt].ptr     = (void *)(wrGetProcAddress((uintptr_t)"grStencilFuncExt"));
    tblGlide2x[FEnum_grStencilMaskExt].ptr     = (void *)(wrGetProcAddress((uintptr_t)"grStencilMaskExt"));
    tblGlide2x[FEnum_grStencilOpExt].ptr       = (void *)(wrGetProcAddress((uintptr_t)"grStencilOpExt"));
    tblGlide2x[FEnum_grLfbConstantStencilExt].ptr = (void *)(wrGetProcAddress((uintptr_t)"grLfbConstantStencilExt"));
    tblGlide2x[FEnum_grSstWinOpenExt].ptr      = (void *)(wrGetProcAddress((uintptr_t)"grSstWinOpenExt"));

    return 0;
}

