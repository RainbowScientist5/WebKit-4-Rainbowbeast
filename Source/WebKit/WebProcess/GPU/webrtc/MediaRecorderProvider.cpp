/*
 * Copyright (C) 2020 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "MediaRecorderProvider.h"

#if ENABLE(MEDIA_RECORDER) && PLATFORM(COCOA)

#include "MediaRecorderPrivate.h"
#include "WebPage.h"
#include <WebCore/MediaRecorderPrivate.h>
#include <WebCore/Page.h>
#include <WebCore/Settings.h>
#include <wtf/TZoneMallocInlines.h>

namespace WebKit {

WTF_MAKE_TZONE_ALLOCATED_IMPL(MediaRecorderProvider);

using namespace WebCore;

std::unique_ptr<WebCore::MediaRecorderPrivate> MediaRecorderProvider::createMediaRecorderPrivate(MediaStreamPrivate& stream, const MediaRecorderPrivateOptions& options)
{
#if ENABLE(GPU_PROCESS) && ENABLE(WEB_RTC)
    auto* page = m_webPage.corePage();
    if (page && page->settings().webRTCPlatformCodecsInGPUProcessEnabled())
        return makeUnique<MediaRecorderPrivate>(stream, options);
#endif
    return WebCore::MediaRecorderProvider::createMediaRecorderPrivate(stream, options);
}

}

#endif // ENABLE(MEDIA_RECORDER) && PLATFORM(COCOA)
