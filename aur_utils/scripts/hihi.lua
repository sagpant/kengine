local object = getEntity("First")

local pos = object:getTransformComponent().boundingBox.topLeft

pos.x = math.random(0, getWindowSize().x / getTileSize().x)
pos.y = math.random(0, getWindowSize().y / getTileSize().y)
