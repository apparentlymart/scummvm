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

#include "base/plugins.h"

#include "common/file.h"
#include "engines/advancedDetector.h"

#include "valhalla/valhalla.h"

namespace Valhalla {
const char *ValhallaEngine::getGameId() const {
	return _gameDescription->gameId;
}
Common::Platform ValhallaEngine::getPlatform() const {
	return _gameDescription->platform;
}
}

static const PlainGameDescriptor ValhallaEngines[] = {{"valhalla", "Valhalla"},
                                                      {0, 0}};

namespace Valhalla {

static const ADGameDescription gameDescriptions[] = {
    // Valhalla Classics Episode 1: The Crypt
    {"valhallaclassicsep01",
     0,
     AD_ENTRY1s("episode-01.exe", "092898530b3358b0e5fb1eb5cb17ffdf", 164864),
     Common::EN_ANY,
     Common::kPlatformWindows,
     ADGF_NO_FLAGS,
     GUIO1(GUIO_NOMIDI)},

    AD_TABLE_END_MARKER};

} // End of namespace Valhalla

class ValhallaMetaEngine : public AdvancedMetaEngine {
public:
	ValhallaMetaEngine()
	    : AdvancedMetaEngine(Valhalla::gameDescriptions,
	                         sizeof(ADGameDescription),
	                         ValhallaEngines) {
	}

	const char *getEngineId() const {
		return "valhalla";
	}

	virtual const char *getName() const {
		return "Valhalla";
	}

	virtual const char *getOriginalCopyright() const {
		return "Valhalla (C) 1994-2014 Vulcan Software";
	}

	virtual bool hasFeature(MetaEngineFeature f) const;
	virtual bool createInstance(OSystem *syst,
	                            Engine **engine,
	                            const ADGameDescription *desc) const;
};

bool ValhallaMetaEngine::hasFeature(MetaEngineFeature f) const {
	return false;
}

bool ValhallaMetaEngine::createInstance(OSystem *syst,
                                        Engine **engine,
                                        const ADGameDescription *desc) const {
	if (desc)
		*engine = new Valhalla::ValhallaEngine(syst, desc);

	return desc != nullptr;
}

#if PLUGIN_ENABLED_DYNAMIC(VALHALLA)
REGISTER_PLUGIN_DYNAMIC(VALHALLA, PLUGIN_TYPE_ENGINE, ValhallaMetaEngine);
#else
REGISTER_PLUGIN_STATIC(VALHALLA, PLUGIN_TYPE_ENGINE, ValhallaMetaEngine);
#endif
