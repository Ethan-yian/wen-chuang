#include "music_defs.h"

// 音符频率表（单位：定时器初值）
unsigned int code FreqTable[]={
    0,      // 休止符频率
    // 低音频率表（1-12）
    63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
    // 中音频率表（13-24）
    64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
    // 高音频率表（25-36）
    65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

// 乐谱数据
// 格式：[音符, 持续时间] 依次排列
// 音符：使用前面定义的音符代号（P, L1-L7, M1-M7, H1-H7）
// 持续时间：以SPEED为基准的相对时值


// 晴天音乐数据（1-10节）
unsigned char code Music1[]={

// 1

L6,2,
M1,2,
M5,2,
M1,2,
L4,2,
L5,1,
L6,1,
M5,2,
M1,2,

//2


L1,2,
L5,2,
M5,2,
M1,2,
L1,2,
M5,2,
L7,2,
M5,2,

//3


L6,2,
M1,2,
M5,2,
L6,2,
L4,2,
L5,1,
L6,1,
M5,2,
M1,2,


//4


L1,2,
L5,2,
M5,2,
M1,2,
L1,2,
M5,2,
L7,1,
M1,1,
M5,2,


//5


L6,2,
M1,2,
M5,2,
M1,2,
L4,2,
L5,1,
L6,1,
M5,2,
M1,2,


//6


L1,2,
L5,2,
M5,2,
M1,2,
L1,2,
M5,2,
L7,2,
M5,2,


//7


L6,2,
M1,2,
M5,2,
L6,2,
L4,2,
L5,1,
L6,1,
M5,2,
M1,2,


//8


L1,2,
L5,2,
M5,2,
M1,2,
L1,2,
M5,2,
L7,1,
M1,1,
M5,2,


//9


P,2,
M5,2,
M5,2,
M1,2,
M1,4,
M2,2,
M3,2,

//10

P,2,
M5,2,
M5,2,
M1,2,
M1,2,
M2,1,
M3,1,
M2,1,
M1,1,
L5,5,


    0xFF  // 结束标记
};



// 晴天音乐数据（11-20节）
unsigned char code Music2[]={

//11

P,2,
M5,2,
M5,2,
M1,2,
M1,4,
M2,2,
M3,2,


//12

P,2,
M3,4,
M2,1,
M3,1,
M4,1,
M3,1,
M2,1,
M4,1,
M3,1,
M2,1,
M1,2,


//13

L5,2,
M1,2,
M1,2,
M3,2,
M4,2,
M3,2,
M2,2,
M1,1,
M2,1,


//14

M3,2,
M3,2,
M3,2,
M3,2,
M2,1,
M3,1,
M2,2,
M1,4,

//15

L5,2,
M1,2,
M2,2,
M3,2,
M4,2,
M3,2,
M2,2,
M1,1,
M2,1,

//16

M3,2,
M3,2,
M3,2,
M3,2,
M2,1,
M3,1,
M2,2,
M1,3,
L7,1,

//17

M1,1,
M1,1,
M1,1,
M1,1,
L7,1,
M1,2,
M1,2,
M1,1,
M1,1,
M1,1,
L7,1,
M1,2,
M1,2,


//18

M1,1,
M1,1,
M1,1,
L7,1,
M1,2,
M1,2,
M1,1,
M1,1,
M1,1,
M5,1,
M5,2,
M5,1,


//19

P,1,
M5,1,
M5,1,
M5,1,
M5,1,
M5,2,
M5,2,
M5,1,
M5,1,
M5,1,
M5,1,
M4,1,
M3,1,
M3,9,
P,4,

//20


M1,1,
M1,1,
M1,1,
M1,1,


    0xFF  // 结束标记
};



// 晴天音乐数据（21-30节）
unsigned char code Music3[]={

//21

L6,2,
L7,2,
M1,2,
M5,2,
M4,2,
M3,2,
M1,2,
M1,6,
P,4,


//22

M1,1,
M1,1,
M1,1,
M1,1,
M3,2,
M1,2,


//23

L6,2,
L7,2,
M1,2,
M5,2,
M4,2,
M3,2,
M1,2,
M2,10,
P,8,


//24


M3,2,
M2,2,
M4,2,
M3,4,
M1,2,
M5,2,
M7,2,


//25

H1,2,
M7,2,
M1,2,
M1,4,
M1,2,
M6,2,
M6,2,

//26

P,2,
M6,2,
M5,2,
M5,4,
M5,2,
M4,2,
M3,2,

//27


M2,2,
M3,2,
M4,2,
M3,10,

//28


M3,2,
M4_,2,
M5_,2,
M3,4,
M4,2,
M5,2,
M7,2,

//29


H2,2,
M7,2,
H1,2,
H1,6,
P,2,
H1,2,

//30


H1,2,
M5,2,
M5,2,
M6,2,
M5,1,
M4,1,
M4,2,
M2,1,
M3,1,


    0xFF  // 结束标记
};




// 晴天音乐数据（30-39节）
unsigned char code Music4[]={

//31


M4,2,
M5,2,
M6,2,
M1,2,
M6,3,
M7,1,
M7,4,
	
	
//32


M3,2,
M2,2,
M4,2,
M3,4,
M1,2,
M5,2,
M7,2,

//33


H1,2,
M5,2,
M5,2,
M6,2,
M5,1,
M4,1,
M4,2,
M2,1,
M3,1,

//34


P,2,
M6,2,
M5,2,
M5,4,
M5,2,
M4,2,
M3,2,

//35


M2,2,
M3,2,
M4,2,
M3,10,

//36


M3,2,
M4_,2,
M5_,2,
M3,4,
M4,2,
M5,2,
M7,2,


//37


H2,2,
M7,2,
H1,2,
H1,6,
P,2,
H1,2,


//38


H1,2,
M5,2,
M5,2,
M6,2,
M5,2,
M4,2,
L6,2,
L7,2,

//39


M1,2,
M2,2,
M3,2,
M2,6,
M3,2,
M1,10,
P,8,


    0xFF  // 结束标记
};







// 七里香音乐数据（1-19节）
unsigned char code Music5[]={

	  // 0节
	M2,	1,
	M3,	1,
	M5,	1,
	M6,	1,
	
		// 1节
	H1,4,
	H1,3,
	H3,1,
	H2,2,
	H1,4,
	M6,1,
	H1,1,
	M6,1,
	
		// 2节	
	M5,3,
	M6,1,
	H1,2,
	H2,2,
	H3,4,
	H2,1,
	H3,1,
	H5,1,
	H6,1,
	
		// 3节	
	H1,4,
	H1,3,
	H3,1,
	H2,2,
	H1,2,
	H1,2,
	M6,2,
	
		// 4节	
	H2,12,
	P,2,
	M5,2,
	
		// 5节	
	H1,4,
	M7,2,
	H1,1,
	H1,5,
	P,2,
	H1,2,
	
		// 6节	
	H1,2,
	M7,2,
	M6,2,
	M7,1,
	M6,3,
	M5,4,
	M5,2,


    0xFF  // 结束标记
};

unsigned char code Music6[]={
		// 7节	
	M5,4,
	M4,2,
	M3,1,
	M5,7,
	M5,2,
	
		// 8节	
	M5,2,
	M6,2,
	M2,2,
	M4,1,
	M4,1,
	M3,2,
	M3,4,
	M5,2,
	
		// 9节	
	H1,4,
	M7,2,
	H1,1,
	H1,5,
	P,2,
	H1,2,
	
		// 10节	
	H1,2,
	M7,2,
	H1,2,
	H2,1,
	H2,1,
	H1,2,
	H1,2,
	H1,2,
	M7,2,
	
		// 11节	
	H1,2,
	H1,1,
	H1,3,
	M7,2,
	M7,1,
	M6,1,
	M6,2,
	M6,2,
	M7,1,
	M6,1,
	M5,8,
	
		// 12节
	P,4,
	M5,2,
	H1,2,


		// 13节
	H1,4,
	M3,2,
	M6,2,
	M6,4,
	M5,2,
	H2,2,	
	
	    0xFF  // 结束标记
};


unsigned char code Music7[]={
		// 14节		
	H2,4,
	M2,2,
	M4,1,
	M4,1,
	M3,2,
	M3,2,
	P,2,
	M5,2,
		
		
		// 15节
	M5,2,
	M4,2,
	M4,2,
	M3,1,
	M3,3,
	M2,2,
	M2,2,
	M1,2,

		
		// 16节
	M3,1,
	M2,1,
	M2,4,
	M4,2,
	M3,4,
	M5,2,
	H1,2,
	
	

		
		// 17节
	H1,4,
	M3,2,
	M6,2,
	M6,2,
	M5,2,
	M5,2,
	H2,2,
	
	
		// 18节
	H2,2,
	M2,2,
	M2,2,
	M4,2,
	M3,2,
	M5,2,
	M5,2,
	H3,2,	
		
		
		// 19节
	H3,2,
	H2,2,
	H2,2,
	H1,2,
	H1,2,
	H2,2,
	H1,2,
	H3,2,
	
		
		// 20节
	H3,2,
	H2,1,
	H2,5,
	P,2,
	M5,2,
	M7,2,
	H1,1,
	H1,1,
	
	
	    0xFF  // 结束标记
};


unsigned char code Music8[]={
    // 音符, 时值,

		// 21节
	H1,4,
	P,2,
	H1,2,
	H1,2,
	M6,1,
	M7,1,
	M6,2,
	M5,2,
		
		
		// 22节
	M7,2,
	H1,2,
	H2,2,
	H1,1,
	H1,3,
	M5,2,
	M7,2,
	H1,1,
	H1,5,

		
		// 23节
	P,2,
	H1,2,
	H1,2,
	M6,1,
	M7,1,
	M6,2,
	M5,2,
		
		
		// 24节
	H2,2,
	H3,2,
	H4,2,
	H3,1,
	H3,3,
	M5,2,
	M7,2,
	H1,1,
	H1,5,
		
		
		// 25节
	P,2,
	H1,2,
	H1,2,
	M6,1,
	M7,1,
	M6,2,
	M5,2,

		
		// 26节
	H2,2,
	H1,2,
	M7,2,
	H1,1,
	H1,5,
	P,2,
	H1,2,
		
		
		// 27节
	H1,2,
	H2,1,
	H3,1,
	H2,2,
	H1,2,
	H1,2,
	M7,2,
	H2,2,
	H1,1,
	H1,1,

		
		// 20节		
	P,2,
	M5,2,
	M7,2,
	H1,1,
	H1,1,
		
		
		// 21节
	H1,4,
	P,2,
	H1,2,
	H1,2,
	M6,1,
	M7,1,
	M6,2,
	M5,2,
		
		
		// 22节
	M7,2,
	H1,2,
	H2,2,
	H1,1,
	H1,3,
	M5,2,
	M7,2,
	H1,1,
	H1,5,

		
		// 23节
	P,2,
	H1,2,
	H1,2,
	M6,1,
	M7,1,
	M6,2,
	M5,2,
		
		
		// 24节
	H2,2,
	H3,2,
	H4,2,
	H3,1,
	H3,3,
	M5,2,
	M7,2,
	H1,1,
	H1,5,
		
		
		// 25节
	P,2,
	H1,2,
	H1,2,
	M6,1,
	M7,1,
	M6,2,
	M5,2,

		
		// 26节
	H2,2,
	H1,2,
	M7,2,
	H1,1,
	H1,5,
	P,2,
	H1,2,
		
		
		// 27节
	H1,2,
	H2,1,
	H3,1,
	H2,2,
	H1,2,
	H1,2,
	M7,2,
	H2,2,
	H1,1,
	H1,1,
	P,4,
	
    0xFF    // 终止符
};