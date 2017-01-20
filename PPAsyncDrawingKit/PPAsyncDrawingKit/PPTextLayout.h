//
//  PPTextLayout.h
//  PPAsyncDrawingKit
//
//  Created by DSKcpp on 2016/10/14.
//  Copyright © 2016年 DSKcpp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PPAsyncDrawingKit/PPTextLayoutFrame.h>
#import <PPAsyncDrawingKit/PPTextRenderer.h>

NS_ASSUME_NONNULL_BEGIN

@interface PPTextLayout : NSObject
@property (nonatomic, strong) NSAttributedString *truncationString;
@property (nonatomic, assign) NSUInteger numberOfLines;
@property (nullable, nonatomic, strong) NSArray<UIBezierPath *> *exclusionPaths;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGPoint origin;
@property (nonatomic, assign) CGRect frame;
@property (nonatomic, strong) NSAttributedString *attributedString;
@property (nonatomic, strong) PPTextLayoutFrame *layoutFrame;
@property (nonatomic, strong) PPTextRenderer *textRenderer;

- (instancetype)initWithAttributedString:(NSAttributedString *)attributedString;
- (nullable PPTextLayoutFrame *)createLayoutFrame;
- (void)setNeedsLayout;
@end

@interface PPTextLayout (PPTextLayoutCoordinates)
- (CGRect)convertRectToCoreText:(CGRect)rect;
- (CGRect)convertRectFromCoreText:(CGRect)rect;
- (CGPoint)convertPointToCoreText:(CGPoint)point;
- (CGPoint)convertPointFromCoreText:(CGPoint)point;
@end

@interface PPTextLayout (PPTextLayoutHitTesting)
- (NSUInteger)characterIndexForPoint:(CGPoint)point;
- (NSRange)characterRangeForBoundingRect:(CGRect)rect;
@end

@interface PPTextLayout (PPTextLayoutResult)
@property (nonatomic, assign, readonly) CGFloat layoutHeight;
@property (nonatomic, assign, readonly) CGSize layoutSize;
@property (nonatomic, assign, readonly) NSUInteger containingLineCount;
@property (nonatomic, assign, readonly) NSRange containingStringRange;
- (CGRect)boundingRectForCharacterRange:(NSRange)range;
- (CGPoint)locationForCharacterAtIndex:(NSUInteger)index;
- (CGRect)enumerateSelectionRectsForCharacterRange:(NSRange)range usingBlock:(nullable void(^)(CGRect rect, BOOL *stop))block;
- (void)enumerateEnclosingRectsForCharacterRange:(NSRange)range usingBlock:(void (^)(CGRect rect, BOOL *stop))block;
- (void)enumerateLineFragmentsForCharacterRange:(NSRange)range usingBlock:(void(^)(CGRect rect, NSRange range, BOOL *stop))block;
- (nullable PPTextFontMetrics *)lineFragmentMetricsForLineAtIndex:(NSUInteger)index effectiveRange:(nullable NSRangePointer)range;
- (CGRect)lineFragmentRectForCharacterAtIndex:(NSUInteger)index effectiveRange:(nullable NSRangePointer)range;
- (CGRect)lineFragmentRectForLineAtIndex:(NSUInteger)index effectiveRange:(nullable NSRangePointer)range;
- (NSUInteger)lineFragmentIndexForCharacterAtIndex:(NSUInteger)index;
- (NSRange)containingStringRangeWithLineLimited:(NSUInteger)lineLimited;
@end

NS_ASSUME_NONNULL_END
