/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***
* Copyright (c) 2008-2012 Appcelerator Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

(function () {
  Ti.Analytics.sendEvent = function (data) {
    // If we're offline we don't even attempt to send Analytics.
    //TODO: we need to place these in DB and re-send later
    if (Ti.Network.online === false) {
      Ti.API.debug("Not online -- skipping analytics");
      return;
    }
    if (!Ti.App.analyticsEnabled) {
      Ti.API.debug("Analytics disabled via tiapp.xml, skipping");
      return;
    }

    queryString = "";
    for (var key in data) {
      queryString += key + "=" + (data[key] === undefined ? '' : Ti.Network.encodeURIComponent(data[key])) + '&';
    }

    // Send the event natively and asynchronously.
    Ti.Analytics._sendEvent(queryString);
  };

  /** Undocumented, perhaps to be deprecated
   * @no_tiapi(method=True,name=Analytics.addEvent,since=0.3)
   * @no_tiapi Send an analytics event associated with the application,
   * @no_tiapi likely to be deprecated in favor of userEvent
   * @no_tiarg[String, event] event name
   * @no_tiarg[String. data] event data
   */
  Ti.Analytics.addEvent = function (event, data) {
    Ti.Analytics.sendEvent({
      type: 'app.addEvent',
      event: event,
      data: data
    });
  };

  /**
   * @tiapi(method=True,name=Analytics.navEvent,since=0.7)
   * @tiapi Send an analytics event associated with application navigation
   * @tiarg[String, from] Navigation starting point, the context we're leaving.
   * @tiarg[String, to] Navigation ending point, the context to which we're going.
   * @tiarg[String, name] Event name.
   * @tiarg[Object, data] Extra event data to pass along. This will be converted to JSON.
   */
  Ti.Analytics.navEvent = function (from, to, name, data) {
    if (from === undefined || to === undefined) return;

    Ti.Analytics.sendEvent({
      type: 'app.nav',
      event: name === undefined ? "app.nav" : name,
      data: JSON.stringify({
        from: from,
        to: to,
        data: data
      })
    });
  };

  /**
   * @tiapi(method=True,name=Analytics.featureEvent,since=0.7)
   * @tiapi Send an analytics event associated with application feature functionality
   * @tiarg[String, name] Feature name.
   * @tiarg[Object, data] Extra event data to pass along. This will be converted to JSON.
   */
  Ti.Analytics.featureEvent = function (name, data) {
    if (name === undefined) return;

    Ti.Analytics.sendEvent({
      type: 'app.feature',
      event: name,
      data: data === undefined ? null : JSON.stringify(data)
    });
  };

  /**
   * @tiapi(method=True,name=Analytics.settingsEvent,since=0.7)
   * @tiapi Send an analytics event associated with application settings or configuration
   * @tiarg[String, name] Setting name.
   * @tiarg[Object, data] Extra event data to pass along. This will be converted to JSON.
   */
  Ti.Analytics.settingsEvent = function (name, data) {
    if (name === undefined) return;

    Ti.Analytics.sendEvent({
      type: 'app.settings',
      event: name,
      data: data === undefined ? null : JSON.stringify(data)
    });
  };

  /**
   * @tiapi(method=True,name=Analytics.timedEvent,since=0.3)
   * @tiapi Send an analytics event tracking the duration of an application action
   * @tiarg[String, event] Event name
   * @tiarg[Date, start] Event start time (optional if duration is specified).
   * @tiarg[Date, stop] Event stop time (optional if duration is specified).
   * @tiarg[Number, duration] Duration in seconds (optional if both start and stop
   * @tiarg are specified)
   * @tiarg[Object, data] Extra event data to pass along. This will be converted to JSON.
   */
  Ti.Analytics.timedEvent = function (name, start, stop, duration, data) {
    // Number in, two-digit (or more) string out
    var zeropad = function (maybe_small_number) {
      return ((maybe_small_number < 10) ? '0' : '') + maybe_small_number;
    }

    // format to yyyy-MM-dd'T'HH:mm:ss.SSSZ to be consistent with
    // TideSDK Mobile UTC timestamp strings.
    var formatUTCstring = function (d) {
      return d.getUTCFullYear().toString() + '-' + zeropad(1 + d.getUTCMonth()) + '-' + zeropad(d.getUTCDate()) + 'T' + zeropad(d.getUTCHours()) + ':' + zeropad(d.getUTCMinutes()) + ':' + zeropad(d.getUTCSeconds()) + '+0000';
    }

    if (name === undefined) return;

    payload = {};
    if (start !== undefined) payload.start = formatUTCstring(start);
    if (stop !== undefined) payload.stop = formatUTCstring(stop);
    if (duration !== undefined) payload.duration = duration;
    if (data !== undefined) payload.data = data;
    Ti.Analytics.sendEvent({
      type: 'app.timed_event',
      event: name,
      data: JSON.stringify(payload)
    });
  };

  /**
   * @tiapi(method=True,name=Analytics.userEvent,since=0.7)
   * @tiapi Send an analytics event not covered by the other interfaces
   * @tiarg[String, name] Event name.
   * @tiarg[Object, data] Extra event data to pass along. This will be converted to JSON.
   */
  Ti.Analytics.userEvent = function (name, data) {
    if (name === undefined) return;

    Ti.Analytics.sendEvent({
      type: 'app.user',
      event: name,
      data: data === undefined ? null : JSON.stringify(data)
    });
  };
})();
