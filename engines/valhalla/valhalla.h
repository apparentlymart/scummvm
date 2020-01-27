/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 *
 */

#ifndef VALHALLA_VALHALLA_H
#define VALHALLA_VALHALLA_H

#include "common/config-manager.h"
#include "common/error.h"
#include "common/scummsys.h"
#include "engines/engine.h"

#include "audio/audiostream.h"
#include "audio/decoders/wave.h"
#include "audio/mixer.h"
#include "common/events.h"
#include "common/file.h"
#include "common/queue.h"
#include "common/system.h"
#include "common/timer.h"
#include "graphics/palette.h"
#include "graphics/screen.h"
#include "graphics/surface.h"
#include "image/bmp.h"

#include "valhalla/console.h"

struct ADGameDescription;

namespace Valhalla {
enum ValhallaDebugChannels { kDebugGeneral = 1 << 0 };

class ValhallaEngine : public Engine {
public:
	ValhallaEngine(OSystem *syst, const ADGameDescription *gameDesc);
	~ValhallaEngine();

	virtual Common::Error run();

	// Detection related functions
	const ADGameDescription *_gameDescription;
	const char *getGameId() const;
	Common::Platform getPlatform() const;

private:
	Console *_console;
};
} // End of namespace Valhalla

#endif
