/*
    File: HspViewController.m
*/

#import "HspViewController.h"


@implementation HspViewController

- (void)dealloc
{
    [super dealloc];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)setHspView:(HspView *)hspview
{
    [self setView:hspview];
    [hspview setParent:self];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    NSLog(@"viewDidAppear");
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    NSLog(@"viewDidDisappear");
}


- (void)actMode:(int)amode
{
    HspView *hspview;
    hspview = (HspView *)self.view;
    [hspview actMode:amode];
    //NSLog(@"actmode%d",amode);
}

@end
