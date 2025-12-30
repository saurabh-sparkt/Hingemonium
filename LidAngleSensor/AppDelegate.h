//
//  AppDelegate.h
//  LidAngleSensor
//
//  Created by Sam on 2025-09-06.
//  Modified by Vedaant on 2025-09-27
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import "HarmoniumAudioEngine.h"
#import "LidAngleSensor.h"
#import "KeyCaptureView.h"
#import "NSLabel.h"

@class KeyCaptureView;

typedef NS_ENUM(NSInteger, NoteNamingMode) {
    NoteNamingModeWestern = 0,
    NoteNamingModeSargam = 1
};

@interface AppDelegate : NSObject <NSApplicationDelegate, KeyCaptureViewDelegate>

@property (nonatomic, strong) NSWindow *window;
@property (nonatomic, strong) HarmoniumAudioEngine *harmoniumEngine;
@property (nonatomic, strong) LidAngleSensor *lidSensor;

// UI Elements
@property (nonatomic, strong) NSLabel *titleLabel;
@property (nonatomic, strong) NSLabel *angleLabel;
@property (nonatomic, strong) NSLabel *scaleLabel;
@property (nonatomic, strong) NSPopUpButton *scalePopUpButton;
@property (nonatomic, strong) NSLabel *notationLabel;
@property (nonatomic, strong) NSPopUpButton *namingModePopUpButton;
@property (nonatomic, strong) NSLabel *airPressureToggleLabel;
@property (nonatomic, strong) NSSwitch *airPressureToggle;
@property (nonatomic, strong) NSLabel *legendLabel;
@property (nonatomic, strong) NSLabel *instructionsLabel;

// Scale and Naming
@property (nonatomic, assign) NoteNamingMode currentNamingMode;
@property (nonatomic, strong) NSArray<NSString *> *availableScales;
@property (nonatomic, strong) NSDictionary<NSString *, NSArray<NSNumber *> *> *scaleNoteMapping;
@property (nonatomic, strong) NSArray<NSNumber *> *mappedKeys;
@property (nonatomic, strong) NSString *currentScale;

// State
@property (nonatomic, strong) NSTimer *updateTimer;
@property (nonatomic, assign) double lastLidAngle;
@property (nonatomic, assign) double lastUpdateTime;
@property (nonatomic, assign) double airPressure;

// Methods
- (void)setupUI;
- (void)setupScales;
- (void)updateLegend;
- (void)update;
- (int)getMidiNoteForKey:(char)key;
- (NSString *)noteNameForMidi:(int)midiNote;
- (void)scaleDidChange:(NSPopUpButton *)sender;
- (void)namingModeDidChange:(NSPopUpButton *)sender;
- (void)toggleDidChange:(NSSwitch *)sender;
- (BOOL)handleKeyDown:(NSEvent *)event;

@end
