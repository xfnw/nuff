/* See LICENSE file for copyright and license details. */

static char *fontfallbacks[] = {
	"space grotesk",
	"league gothic",
	"noto sans",
	"dejavu sans",
	"roboto",
	"ubuntu",
	"comic sans ms",
	"shantell sans",
	"vcr osd mono",
};
#define NUMFONTSCALES 42
#define FONTSZ(x) ((int)(10.0 * powf(1.1288, (x)))) /* x in [0, NUMFONTSCALES-1] */

static char *colors[] = {
	"#000000", /* foreground color */
	"#FFFFFF", /* background color */
};

static const float linespacing = 1.1;

/* how much screen estate is to be used at max for the content */
static const float usablewidth = 0.75;
static const float usableheight = 0.75;

/* height of the presentation progress bar */
static int progressheight = 5;

static Mousekey mshortcuts[] = {
	/* button         function        argument */
	{ Button1,        advance,        {.i = +1} },
	{ Button3,        advance,        {.i = -1} },
	{ Button4,        advance,        {.i = -1} },
	{ Button5,        advance,        {.i = +1} },
};

static Shortcut shortcuts[] = {
	/* keysym         function        argument */
	{ XK_Escape,      quit,           {0} },
	{ XK_q,           quit,           {0} },
	{ XK_Right,       advance,        {.i = +1} },
	{ XK_Left,        advance,        {.i = -1} },
	{ XK_Return,      advance,        {.i = +1} },
	{ XK_space,       advance,        {.i = +1} },
	{ XK_BackSpace,   advance,        {.i = -1} },
	{ XK_l,           advance,        {.i = +1} },
	{ XK_h,           advance,        {.i = -1} },
	{ XK_j,           advance,        {.i = +1} },
	{ XK_k,           advance,        {.i = -1} },
	{ XK_Down,        advance,        {.i = +1} },
	{ XK_Up,          advance,        {.i = -1} },
	{ XK_Next,        advance,        {.i = +1} },
	{ XK_Prior,       advance,        {.i = -1} },
	{ XK_n,           advance,        {.i = +1} },
	{ XK_p,           advance,        {.i = -1} },
	{ XK_r,           reload,         {0} },
	{ XK_b,           blank,          {0} },
};

