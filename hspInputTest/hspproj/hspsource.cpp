//
//	hsp3cnv(3.5b5) generated source
//	[main.ax]
//
#include "hsp3r.h"

#define _HSP3CNV_DATE "2025/03/15"
#define _HSP3CNV_TIME "13:49:44"
#define _HSP3CNV_MAXVAR 1
#define _HSP3CNV_MAXHPI 32
#define _HSP3CNV_VERSION 0x360
#define _HSP3CNV_BOOTOPT 4096

/*-----------------------------------------------------------*/

static PVal *Var_0;

/*-----------------------------------------------------------*/

void __HspEntry( void ) {
	// Var initalize
	Var_0 = &mem_var[0];

	// objsize 300, 20
	PushInt(20); 
	PushInt(300); 
	Extcmd(22,2);
	// _HspVar0 ="入力してください..."
	PushStr("入力してください..."); 
	VarSet(Var_0,0);
	// pos 10, 10
	PushInt(10); 
	PushInt(10); 
	Extcmd(17,2);
	// input _HspVar0
	PushVAP(Var_0,0); 
	Extcmd(39,1);
	// repeat
	PushLabel(0); 
	PushLabel(2); Prgcmd(4,2); return;
	TaskSwitch(2);
}

static void L0002( void ) {
	// redraw 1
	PushInt(1); 
	Extcmd(27,1);
	// await 1000/60
	PushInt(16);/*OPT*/ 
	Prgcmd(8,1);
	TaskSwitch(3);
}

static void L0003( void ) {
	// loop 
	Prgcmd(5,0);
	return;
	TaskSwitch(0);
}

static void L0000( void ) {
	TaskSwitch(1);
}

static void L0001( void ) {
	// stop 
	Prgcmd(17,0);
	return;
	// goto 
	Prgcmd(0,0);
	return;
}

//-End of Source-------------------------------------------

CHSP3_TASK __HspTaskFunc[]={
(CHSP3_TASK) L0000,
(CHSP3_TASK) L0001,
(CHSP3_TASK) L0002,
(CHSP3_TASK) L0003,
(CHSP3_TASK) 0,

};

/*-----------------------------------------------------------*/


/*-----------------------------------------------------------*/

void __HspInit( Hsp3r *hsp3 ) {
	hsp3->Reset( _HSP3CNV_MAXVAR, _HSP3CNV_MAXHPI );
	hsp3->SetDataName( 0 );
	hsp3->SetFInfo( 0, 0 );
	hsp3->SetLInfo( 0, 0 );
	hsp3->SetMInfo( 0, 0 );
}

/*-----------------------------------------------------------*/

