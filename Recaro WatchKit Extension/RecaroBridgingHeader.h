//
//  RecaroBridgingHeader.h
//  Respring
//
//  Created by Somica on 09/06/2021.
//

#ifndef RecaroBridgingHeader_h
#define RecaroBridgingHeader_h

#import <UIKit/UIKit.h>

@protocol CAMediaTiming

@property (assign) double beginTime;
@property (assign) double duration;
@property (assign) float speed;
@property (assign) double timeOffset;
@property (assign) float repeatCount;
@property (assign) double repeatDuration;
@property (assign) BOOL autoreverses;
@required
-(void)setSpeed:(float)arg1;
-(double)duration;
-(void)setDuration:(double)arg1;
-(float)repeatCount;
-(double)beginTime;
-(float)speed;
-(double)timeOffset;
-(void)setFillMode:(id)arg1;
-(void)setBeginTime:(double)arg1;
-(void)setRepeatCount:(float)arg1;
-(void)setAutoreverses:(BOOL)arg1;
-(void)setTimeOffset:(double)arg1;
-(BOOL)autoreverses;
-(NSString *)fillMode;
-(void)setRepeatDuration:(double)arg1;
-(double)repeatDuration;
@end

@interface CAAnimation: NSObject <CAMediaTiming>
+(nonnull instancetype)animationWithKeyPath:(NSString *)arg1 ;
@property(getter=isRemovedOnCompletion) BOOL removedOnCompletion;
@property(readonly) CFTimeInterval settlingDuration;
@end

@protocol CAAnimationDelegate <NSObject>

@optional
-(void)animationDidStart:(CAAnimation *)arg1;
-(void)animationDidStop:(CAAnimation *)arg1 finished:(bool)arg2;
@end

@interface CAAnimation (Delegate)
@property(nullable, strong) id <CAAnimationDelegate> delegate;
@end

@interface CALayer : NSObject
@property BOOL masksToBounds;
@property CGFloat cornerRadius;
- (instancetype)initWithLayer:(id)layer;
- (instancetype)init;
@property CGRect frame;
- (void)removeFromSuperlayer;
@property(nullable, copy) NSArray<__kindof CALayer *> *sublayers;
- (void)addSublayer:(CALayer *)layer;
- (void)insertSublayer:(CALayer *)layer atIndex:(unsigned)idx;
- (void)insertSublayer:(CALayer *)layer below:(nullable CALayer *)sibling;
- (void)insertSublayer:(CALayer *)layer above:(nullable CALayer *)sibling;
- (void)addAnimation:(CAAnimation *)anim forKey:(nullable NSString *)key;
@property(nullable, strong) id <CAAnimationDelegate> delegate;
@property (assign) double duration;
@end

typedef NSString * CAGradientLayerType NS_TYPED_ENUM;
const CAGradientLayerType kCAGradientLayerRadial;

@interface CAGradientLayer: CALayer
@property CGPoint startPoint;
@property CGPoint endPoint;
@property(nullable, copy) NSArray *colors;
@property(copy) CAGradientLayerType type;
@property(nullable, copy) NSArray<NSNumber *> *locations;
@end

@interface UIScreen: NSObject
@property(class, nonatomic, readonly) UIScreen *mainScreen;
@end

@interface UIResponder : NSObject
@end

@interface UIView : UIResponder
@property(nonatomic,readonly,strong) CALayer *layer;
@property(nonatomic) CGAffineTransform transform;
@property(nonatomic)                 CGFloat           alpha;
- (nullable UIView *)snapshotViewAfterScreenUpdates:(BOOL)afterUpdates;
- (void)layoutSubviews;
@property(nonatomic) CGRect            bounds;
@property(nonatomic) BOOL translatesAutoresizingMaskIntoConstraints;
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
@end

@interface UIWindow: UIView
@property(nonatomic,readonly,getter=isKeyWindow) BOOL keyWindow;
@end

@interface UIView (WindowHierachy)

@property(nullable, nonatomic,readonly) UIView       *superview;
@property(nonatomic,readonly,copy) NSArray<__kindof UIView *> *subviews;
@property(nullable, nonatomic,readonly) UIWindow     *window;

- (void)removeFromSuperview;
- (void)insertSubview:(UIView *)view atIndex:(NSInteger)index;
- (void)exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;

- (void)addSubview:(UIView *)view;
- (void)insertSubview:(UIView *)view belowSubview:(UIView *)siblingSubview;
- (void)insertSubview:(UIView *)view aboveSubview:(UIView *)siblingSubview;

- (void)bringSubviewToFront:(UIView *)view;
- (void)sendSubviewToBack:(UIView *)view;

- (void)didAddSubview:(UIView *)subview;
- (void)willRemoveSubview:(UIView *)subview;

- (void)willMoveToSuperview:(nullable UIView *)newSuperview;
- (void)didMoveToSuperview;
- (void)willMoveToWindow:(nullable UIWindow *)newWindow;
- (void)didMoveToWindow;

@end

@interface UIViewController: UIResponder
// This property has been replaced by presentedViewController.
@property(nullable, nonatomic,readonly) UIViewController *modalViewController API_DEPRECATED("", ios(2.0, 6.0)) API_UNAVAILABLE(tvos);

@property(null_resettable, nonatomic,strong) UIView *view;

// The view controller that was presented by this view controller or its nearest ancestor.
@property(nullable, nonatomic,readonly) UIViewController *presentedViewController;

// The view controller that presented this view controller (or its farthest ancestor.)
@property(nullable, nonatomic,readonly) UIViewController *presentingViewController;
@end

@interface UIWindow (UIViewController)
@property(nullable, nonatomic,strong) UIViewController *rootViewController API_AVAILABLE(ios(4.0));

@end


@interface UIViewAnimating: NSObject
- (void)startAnimation;
@end

typedef NS_ENUM(NSInteger, UIViewAnimatingPosition) {
    UIViewAnimatingPositionEnd,
    UIViewAnimatingPositionStart,
    UIViewAnimatingPositionCurrent,
};

@interface UIViewPropertyAnimator: UIViewAnimating
- (instancetype)initWithDuration:(NSTimeInterval)duration dampingRatio:(CGFloat)ratio animations:(void (^ __nullable)(void))animations;
- (void)addCompletion:(void (^)(UIViewAnimatingPosition finalPosition))completion;
@end

@interface UIApplication : UIResponder
@property(class, nonatomic, readonly) UIApplication *sharedApplication;
@property(nonatomic,readonly) NSArray<__kindof UIWindow *>  *windows;
@end

@interface CAPropertyAnimation : CAAnimation
@property (copy) NSString * keyPath;
@end

@interface CABasicAnimation: CAPropertyAnimation

@property (retain) id byValue;
@property double endAngle;
@property (retain) id fromValue;
@property bool roundsToInteger;
@property double startAngle;
@property (retain) id toValue;
@end

@interface NSLayoutConstraint: NSObject
@property (getter=isActive) BOOL active API_AVAILABLE(macos(10.10), ios(8.0));
@end

@interface NSLayoutAnchor: NSObject
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor *)anchor __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor *)anchor __attribute__((warn_unused_result));
@end


@interface NSLayoutYAxisAnchor: NSLayoutAnchor
@end

@interface NSLayoutXAxisAnchor: NSLayoutAnchor
@end

@interface NSLayoutDimension: NSLayoutAnchor
@end


@interface UIView (Anchor)
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *leadingAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *trailingAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *leftAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *rightAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *topAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *bottomAnchor;
@property(nonatomic,readonly,strong) NSLayoutDimension *widthAnchor;
@property(nonatomic,readonly,strong) NSLayoutDimension *heightAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *centerXAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *centerYAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *firstBaselineAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *lastBaselineAnchor;
@end

typedef NS_OPTIONS(NSUInteger, UIControlEvents) {
    UIControlEventTouchDown                                         = 1 <<  0,      // on all touch downs
    UIControlEventTouchDownRepeat                                   = 1 <<  1,      // on multiple touchdowns (tap count > 1)
    UIControlEventTouchDragInside                                   = 1 <<  2,
    UIControlEventTouchDragOutside                                  = 1 <<  3,
    UIControlEventTouchDragEnter                                    = 1 <<  4,
    UIControlEventTouchDragExit                                     = 1 <<  5,
    UIControlEventTouchUpInside                                     = 1 <<  6,
    UIControlEventTouchUpOutside                                    = 1 <<  7,
    UIControlEventTouchCancel                                       = 1 <<  8,

    UIControlEventValueChanged                                      = 1 << 12,     // sliders, etc.
    UIControlEventPrimaryActionTriggered API_AVAILABLE(ios(9.0))    = 1 << 13,     // semantic action: for buttons, etc.
    UIControlEventMenuActionTriggered API_AVAILABLE(ios(14.0))      = 1 << 14,     // triggered when the menu gesture fires but before the menu presents

    UIControlEventEditingDidBegin                                   = 1 << 16,     // UITextField
    UIControlEventEditingChanged                                    = 1 << 17,
    UIControlEventEditingDidEnd                                     = 1 << 18,
    UIControlEventEditingDidEndOnExit                               = 1 << 19,     // 'return key' ending editing

    UIControlEventAllTouchEvents                                    = 0x00000FFF,  // for touch events
    UIControlEventAllEditingEvents                                  = 0x000F0000,  // for UITextField
    UIControlEventApplicationReserved                               = 0x0F000000,  // range available for application use
    UIControlEventSystemReserved                                    = 0xF0000000,  // range reserved for internal framework use
    UIControlEventAllEvents                                         = 0xFFFFFFFF
};

typedef NS_OPTIONS(NSUInteger, UIControlState) {
    UIControlStateNormal       = 0,
    UIControlStateHighlighted  = 1 << 0,                  // used when UIControl isHighlighted is set
    UIControlStateDisabled     = 1 << 1,
    UIControlStateSelected     = 1 << 2,                  // flag usable by app (see below)
    UIControlStateFocused API_AVAILABLE(ios(9.0)) = 1 << 3, // Applicable only when the screen supports focus
    UIControlStateApplication  = 0x00FF0000,              // additional flags available for application use
    UIControlStateReserved     = 0xFF000000               // flags reserved for internal framework use
};

@interface UIControl : UIView
@property(nonatomic,getter=isEnabled) BOOL enabled;                                  // default is YES. if NO, ignores touch events and subclasses may draw differently
@property(nonatomic,getter=isSelected) BOOL selected;                                // default is NO may be used by some subclasses or by application
@property(nonatomic,getter=isHighlighted) BOOL highlighted;
- (void)addTarget:(nullable id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
@end

@interface UIButton: UIControl
- (void)setTitle:(nullable NSString *)title forState:(UIControlState)state;
@end

@interface PUICApplication : UIApplication
+ (instancetype)sharedPUICApplication;
- (void)_setStatusBarTimeHidden:(_Bool)arg1 animated:(_Bool)arg2 completion:(void (^)(void))arg3;
@end

#endif /* RecaroBridgingHeader_h */
