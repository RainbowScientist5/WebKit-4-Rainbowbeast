/*
 * Copyright (C) 2022 Apple Inc. All rights reserved.
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

#pragma once

#if USE(LIBWEBRTC) && PLATFORM(COCOA) && ENABLE(GPU_PROCESS) && ENABLE(WEB_CODECS)

#include <WebCore/VideoDecoder.h>
#include <WebCore/VideoEncoder.h>
#include <wtf/TZoneMalloc.h>

namespace WebKit {

class WebProcess;

class RemoteVideoCodecFactory {
    WTF_MAKE_TZONE_ALLOCATED(RemoteVideoCodecFactory);
public:
    explicit RemoteVideoCodecFactory(WebProcess&);
    ~RemoteVideoCodecFactory();

private:
    static void createDecoder(const String&, const WebCore::VideoDecoder::Config&, WebCore::VideoDecoder::CreateCallback&&, WebCore::VideoDecoder::OutputCallback&&);
    static void createEncoder(const String&, const WebCore::VideoEncoder::Config&, WebCore::VideoEncoder::CreateCallback&&, WebCore::VideoEncoder::DescriptionCallback&&, WebCore::VideoEncoder::OutputCallback&&);
};

} // namespace WebKit

#endif // USE(LIBWEBRTC) && PLATFORM(COCOA) && ENABLE(GPU_PROCESS)
