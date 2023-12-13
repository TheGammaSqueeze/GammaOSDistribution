-- The script concatenates PROCESS_CPU_TIME and PROCESS_MEMORY_STATE atom
-- data for Google Maps. The process name for Google Maps is hardcoded in
-- GOOGLE_MAPS_PROCESS_NAME
-- The script produces a result when it has the following 3 things:
-- (1) received PROCESS_CPU_TIME atom on google maps
-- (2) received PROCESS_MEMORY_STATE atom on google maps
-- (3) received wifi netstats data at least 5 times


-- find index of value in the array
function indexOf(array, value)
    for i, v in ipairs(array) do
        if v == value then
            return i
        end
    end
    return nil
end

GOOGLE_MAPS_PROCESS_NAME = 'com.google.android.apps.maps'
MIN_NETSTATS_DATA_RECEIVED = 5

function onProcessCpuTime(published_data, state)
    local processNameArray = published_data['process_name']
    local mapsIndex = indexOf(processNameArray, GOOGLE_MAPS_PROCESS_NAME)
    -- if there is no atom data for Google Maps process, return
    if mapsIndex == nil then
        on_success(state)
    end
    state['received cpu time'] = true
    for key, valueArray in pairs(published_data) do
        state[key] = valueArray[mapsIndex]
    end
    -- finalize report iff there is (1) 5 pieces of data from wifi (2) any data from process memory
    if (state['received wifi'] >= MIN_NETSTATS_DATA_RECEIVED and state['received process memory'] ~= nil) then
        on_script_finished(state)
    else
        on_success(state)
    end
end

function onProcessMemory(published_data, state)
    local processNameArray = published_data['process_name']
    local mapsIndex = indexOf(processNameArray, GOOGLE_MAPS_PROCESS_NAME)
    -- if there is no atom data for Google Maps process, return
    if mapsIndex == nil then
        on_success(state)
    end
    state['received memory'] = true
    for key, valueArray in pairs(published_data) do
        state[key] = valueArray[mapsIndex]
    end
    -- finalize report iff there is (1) 5 pieces of data from wifi (2) any data from process cpu time
    if (state['received wifi'] >= MIN_NETSTATS_DATA_RECEIVED and state['received cpu time'] ~= nil) then
        on_script_finished(state)
    else
        on_success(state)
    end
end

function onWifiNetstats(published_data, state)
    if state['received wifi'] == nil then
        state['received wifi'] = 0
    end
    state['received wifi'] = state['received wifi'] + 1
    if state['received wifi'] >= MIN_NETSTATS_DATA_RECEIVED and state['received memory'] ~= nil and state['received cpu time'] ~= nil then
        on_script_finished(state)
    else
        on_success(state)
    end
end