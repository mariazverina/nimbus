//
// Copyright 2011 Jeff Verkoeyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "ASIHTTPRequestDelegate.h"
#import "NIProcessorHTTPRequest.h"

@interface NetworkPhotoAlbumViewController : NIToolbarPhotoViewController <
  ASIHTTPRequestDelegate
> {
@private
  NSOperationQueue* _queue;

  NIImageMemoryCache* _highQualityImageCache;
  NIImageMemoryCache* _thumbnailImageCache;
}

/**
 * The high quality image cache.
 *
 * All original-sized photos are stored in this cache.
 *
 * By default the cache is unlimited with a max stress size of 1024*1024*3 pixels.
 *
 * Images are stored with a name that corresponds directly to the photo index in the form "%d".
 *
 * This is unloaded when the controller's view is unloaded from memory.
 */
@property (nonatomic, readonly, retain) NIImageMemoryCache* highQualityImageCache;

/**
 * The thumbnail image cache.
 *
 * All thumbnail photos are stored in this cache.
 *
 * By default the cache is unlimited.
 *
 * Images are stored with a name that corresponds directly to the photo index in the form "%d".
 *
 * This is unloaded when the controller's view is unloaded from memory.
 */
@property (nonatomic, readonly, retain) NIImageMemoryCache* thumbnailImageCache;

/**
 * The operation queue that runs all of the network and processing operations.
 *
 * This is unloaded when the controller's view is unloaded from memory.
 */
@property (nonatomic, readonly, retain) NSOperationQueue* queue;

/**
 * Generate the in-memory cache key for the given index.
 */
- (NSString *)cacheKeyForPhotoIndex:(NSInteger)photoIndex;

/**
 * Request an image from a source URL and store the result in the corresponding image cache.
 *
 *      @param source       The image's source URL path.
 *      @param photoSize    The size of the photo being requested.
 *      @param photoIndex   The photo index used to store the image in the memory cache.
 */
- (void)requestImageFromSource: (NSString *)source
                     photoSize: (NIPhotoScrollViewPhotoSize)photoSize
                    photoIndex: (NSInteger)photoIndex;

@end
