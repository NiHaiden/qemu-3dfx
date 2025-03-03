#include "mgldefs.h"
#include "mglfunci.h"

int szgldata(int, int);
int szglname(int);

typedef struct {
    int enable;
    int size;
    int type;
    int stride;
    void *ptr;
} vtxarry_t;

#define PAGE_SIZE       0x1000

#define MESAGL_MAGIC    0x5b5eb5e5
#define MESAGL_HWNDC    0x574e4443
#define MESAGL_HPBDC    0x50424443
#define MESA_FIFO_BASE  0xec000000
#define MESA_FBTM_BASE  0xea000000

#define MBUFO_BASE      (0xE0U << 24)
#define MBUFO_SIZE      (0x08U << 24)

#define ALIGNED(x)                              ((x%8)?(((x>>3)+1)<<3):x)
#define ALIGNBO(x)                              ((x%16)?(((x>>4)+1)<<4):x)
#define MGLFBT_SIZE                             0x2000000
#define MGLSHM_SIZE                             0x3ffc000
#define FIRST_FIFO                              24
#define MAX_FIFO                                0xc0000
#define MAX_DATA                                ((MGLSHM_SIZE - (4*MAX_FIFO) - (4*4096)) >> 2)
#define MAX_LVLCNTX                             ((MESAGL_MAGIC & 0x0FU) + 1)
#define MAX_TEXUNIT                             8
#define MAX_PBUFFER                             16

#define COMMIT_SIGN \
    const char rev_[ALIGNED(1)]
