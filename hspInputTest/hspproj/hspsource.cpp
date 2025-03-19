//
//	hsp3cnv(3.5b5) generated source
//	[main.ax]
//
#include "hsp3r.h"

#define _HSP3CNV_DATE "2025/03/19"
#define _HSP3CNV_TIME "15:45:56"
#define _HSP3CNV_MAXVAR 4
#define _HSP3CNV_MAXHPI 32
#define _HSP3CNV_VERSION 0x360
#define _HSP3CNV_BOOTOPT 4096

/*-----------------------------------------------------------*/

static PVal *Var_0;
static PVal *Var_1;
static PVal *Var_2;
static PVal *Var_3;

/*-----------------------------------------------------------*/

void __HspEntry(void)
{
    // Var initalize
    Var_0 = &mem_var[0];
    Var_1 = &mem_var[1];
    Var_2 = &mem_var[2];
    Var_3 = &mem_var[3];

    // objsize 300, 60
    PushInt(60);
    PushInt(300);
    Extcmd(22, 2);
    // pos 10, 10
    PushInt(10);
    PushInt(10);
    Extcmd(17, 2);
    // button 	gosub "キーボード表\示", *L0000
    PushLabel(0);
    PushStr("キーボード表\示");
    PushInt(1);
    Extcmd(0, 3);
    // pos 320, 10
    PushInt(10);
    PushInt(320);
    Extcmd(17, 2);
    // button 	gosub "パスワード表\示にする", *L0001
    PushLabel(1);
    PushStr("パスワード表\示にする");
    PushInt(1);
    Extcmd(0, 3);
    // _HspVar0 =stat
    PushSysvar(3, 0);
    VarSet(Var_0, 0);
    // repeat
    PushLabel(2);
    PushLabel(4);
    Prgcmd(4, 2);
    return;
    TaskSwitch(4);
}

static void L0004(void)
{
    //  _HspVar1, "keyboard_text"
    PushStr("keyboard_text");
    PushVAP(Var_1, 0);
    Extcmd(71, 2);
    // redraw 0
    PushInt(0);
    Extcmd(27, 1);
    // if _HspVar1=""
    PushVar(Var_1, 0);
    PushStr("");
    CalcEqI();
    if (HspIf())
    {
        TaskSwitch(5);
        return;
    }
    // objprm _HspVar0, "キーボード表\示"
    PushStr("キーボード表\示");
    PushVAP(Var_0, 0);
    Extcmd(50, 2);
    TaskSwitch(6);
}

static void L0005(void)
{
    // else
    // objprm _HspVar0, _HspVar1
    PushVAP(Var_1, 0);
    PushVAP(Var_0, 0);
    Extcmd(50, 2);
    TaskSwitch(6);
}

static void L0006(void)
{
    // redraw 1
    PushInt(1);
    Extcmd(27, 1);
    // stick _HspVar2
    PushVAP(Var_2, 0);
    Extcmd(52, 1);
    // if _HspVar2&256
    PushVar(Var_2, 0);
    PushInt(256);
    CalcAndI();
    if (HspIf())
    {
        TaskSwitch(7);
        return;
    }
    //  "close_keyboard"
    PushStr("close_keyboard");
    Extcmd(74, 1);
    TaskSwitch(7);
}

static void L0007(void)
{
    // await 1000/60
    PushInt(16); /*OPT*/
    Prgcmd(8, 1);
    TaskSwitch(8);
}

static void L0008(void)
{
    // loop
    Prgcmd(5, 0);
    return;
    TaskSwitch(0);
}

static void L0000(void)
{
    TaskSwitch(2);
}

static void L0002(void)
{
    //  "open_keyboard"
    PushStr("open_keyboard");
    Extcmd(74, 1);
    // return
    Prgcmd(2, 0);
    return;
    TaskSwitch(1);
}

static void L0001(void)
{
    // if _HspVar3=0
    PushVar(Var_3, 0);
    PushInt(0);
    CalcEqI();
    if (HspIf())
    {
        TaskSwitch(9);
        return;
    }
    // _HspVar3 =1
    PushInt(1);
    VarSet(Var_3, 0);
    TaskSwitch(10);
}

static void L0009(void)
{
    // else
    // _HspVar3 =0
    PushInt(0);
    VarSet(Var_3, 0);
    TaskSwitch(10);
}

static void L0010(void)
{
    //  "set_keyboard_secure", _HspVar3
    PushVAP(Var_3, 0);
    PushStr("set_keyboard_secure");
    Extcmd(74, 2);
    // return
    Prgcmd(2, 0);
    return;
    TaskSwitch(3);
}

static void L0003(void)
{
    // stop
    Prgcmd(17, 0);
    return;
    // goto
    Prgcmd(0, 0);
    return;
}

//-End of Source-------------------------------------------

CHSP3_TASK __HspTaskFunc[] = {
    (CHSP3_TASK)L0000,
    (CHSP3_TASK)L0001,
    (CHSP3_TASK)L0002,
    (CHSP3_TASK)L0003,
    (CHSP3_TASK)L0004,
    (CHSP3_TASK)L0005,
    (CHSP3_TASK)L0006,
    (CHSP3_TASK)L0007,
    (CHSP3_TASK)L0008,
    (CHSP3_TASK)L0009,
    (CHSP3_TASK)L0010,
    (CHSP3_TASK)0,

};

/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/

void __HspInit(Hsp3r *hsp3)
{
    hsp3->Reset(_HSP3CNV_MAXVAR, _HSP3CNV_MAXHPI);
    hsp3->SetDataName(0);
    hsp3->SetFInfo(0, 0);
    hsp3->SetLInfo(0, 0);
    hsp3->SetMInfo(0, 0);
}

/*-----------------------------------------------------------*/
