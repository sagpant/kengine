if (not counter) then
    counter = 0
end

counter = counter + getDeltaFrames()

local object = getEntity("First")

local pos = object:getTransformComponent().boundingBox.topLeft

if (counter > 60) then
    pos.x = math.random(0, getWindowSize().x / getTileSize().x)
    pos.y = math.random(0, getWindowSize().y / getTileSize().y)
    counter = 0
end

