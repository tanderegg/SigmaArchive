#pragma  once

#include "../IFactory.h"
#include "../ISystem.h"

#include <string>
#include <vector>
#include <map>

class Property;
class IMoverComponent;

class SimplePhysics
    : public IFactory, public ISystem<IMoverComponent> {
public:
	SimplePhysics() { }
	~SimplePhysics() { };
	/**
	 * \brief Starts the Simple Physics system.
	 *
	 * \returns bool Returns false on startup failure.
	 */
	bool Start() { }

	/**
	 * \brief Causes an update in the system based on the change in time.
	 *
	 * Updates the state of the system based off how much time has elapsed since the last update.
	 * \param[in] const float delta The change in time since the last update
	 * \returns bool Returns true if we had an update interval passed.
	 */
	bool Update(const double delta);

    std::map<std::string,FactoryFunction> getFactoryFunctions();
	void createPhysicsMover(const std::string type, const unsigned int entityID, std::vector<Property> &properties) ;
	void createViewMover(const std::string type, const unsigned int entityID, std::vector<Property> &properties) ;
private:
};
