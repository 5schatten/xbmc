/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "DVDResource.h"
#include "threads/CriticalSection.h"

#include <ass/ass.h>

 /** Wrapper for Libass **/

class CDVDSubtitlesLibass : public IDVDResourceCounted<CDVDSubtitlesLibass>
{
public:
  CDVDSubtitlesLibass();
  ~CDVDSubtitlesLibass() override;

  ASS_Image* RenderImage(int frameWidth, int frameHeight, int videoWidth, int videoHeight, int sourceWidth, int sourceHeight,
                         double pts, int useMargin = 0, double position = 0.0, int* changes = NULL);
  ASS_Event* GetEvents();

  int GetNrOfEvents();

  bool DecodeHeader(char* data, int size);
  bool DecodeDemuxPkt(char* data, int size, double start, double duration);
  bool CreateTrack(char* buf, size_t size);

private:
  ASS_Library* m_library = nullptr;
  ASS_Track* m_track = nullptr;
  ASS_Renderer* m_renderer = nullptr;
  CCriticalSection m_section;
};

