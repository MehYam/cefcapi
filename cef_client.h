// Copyright (c) 2014 The cefcapi authors. All rights reserved.
// License: BSD 3-clause.
// Website: https://github.com/CzarekTomczak/cefcapi

#pragma once

#include "cef_base.h"
#include "include/capi/cef_client_capi.h"

// ----------------------------------------------------------------------------
// struct _cef_client_t
// ----------------------------------------------------------------------------

///
// Implement this structure to provide handler implementations.
///

///
// Return the handler for context menus. If no handler is provided the default
// implementation will be used.
///

struct CEF_CALLBACK _cef_context_menu_handler_t* get_context_menu_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_context_menu_handler\n");
    return NULL;
}

///
// Return the handler for dialogs. If no handler is provided the default
// implementation will be used.
///
struct CEF_CALLBACK _cef_dialog_handler_t* get_dialog_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_dialog_handler\n");
    return NULL;
}

///
// Return the handler for browser display state events.
///
struct CEF_CALLBACK _cef_display_handler_t* get_display_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_display_handler\n");
    return NULL;
}

///
// Return the handler for download events. If no handler is returned downloads
// will not be allowed.
///
struct CEF_CALLBACK _cef_download_handler_t* get_download_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_download_handler\n");
    return NULL;
}

///
// Return the handler for drag events.
///
struct CEF_CALLBACK _cef_drag_handler_t* get_drag_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_drag_handler\n");
    return NULL;
}

///
// Return the handler for focus events.
///
struct CEF_CALLBACK _cef_focus_handler_t* get_focus_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_focus_handler\n");
    return NULL;
}

///
// Return the handler for geolocation permissions requests. If no handler is
// provided geolocation access will be denied by default.
///
struct CEF_CALLBACK _cef_geolocation_handler_t* get_geolocation_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_geolocation_handler\n");
    return NULL;
}

///
// Return the handler for JavaScript dialogs. If no handler is provided the
// default implementation will be used.
///
struct CEF_CALLBACK _cef_jsdialog_handler_t* get_jsdialog_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_jsdialog_handler\n");
    return NULL;
}

///
// Return the handler for keyboard events.
///
struct CEF_CALLBACK _cef_keyboard_handler_t* get_keyboard_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_keyboard_handler\n");
    return NULL;
}

///
// Return the handler for browser life span events.
///
struct CEF_CALLBACK _cef_life_span_handler_t* get_life_span_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_life_span_handler\n");
    return NULL;
}

///
// Return the handler for browser load status events.
///
struct CEF_CALLBACK _cef_load_handler_t* get_load_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_load_handler\n");
    return NULL;
}

///
// Return the handler for off-screen rendering events.
///
struct CEF_CALLBACK _cef_render_handler_t* get_render_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_render_handler\n");
    return NULL;
}

///
// Return the handler for browser request events.
///
struct CEF_CALLBACK _cef_request_handler_t* get_request_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_request_handler\n");
    return NULL;
}

///
// Called when a new message is received from a different process. Return true
// (1) if the message was handled or false (0) otherwise. Do not keep a
// reference to or attempt to access the message outside of this callback.
///
int CEF_CALLBACK on_process_message_received(
        struct _cef_client_t* self,
        struct _cef_browser_t* browser, cef_process_id_t source_process,
        struct _cef_process_message_t* message) {
    DEBUG_CALLBACK("on_process_message_received\n");
    return 0;
}

void initialize_client_handler(struct _cef_client_t* client) {
    DEBUG_CALLBACK("initialize_client_handler\n");
    client->base.size = sizeof(struct _cef_client_t);
    initialize_cef_base(client);
    // callbacks
    const void* methods[] = {
        &get_context_menu_handler,
        &get_dialog_handler,
        &get_display_handler,
        &get_download_handler,
        &get_drag_handler,
        &get_focus_handler,
        &get_geolocation_handler,
        &get_jsdialog_handler,
        &get_keyboard_handler,
        &get_life_span_handler,
        &get_load_handler,
        &get_render_handler,
        &get_request_handler,
        &on_process_message_received,
        NULL
    };
    void* ptr = (void*)client + sizeof(struct _cef_base_t);
    initialize_cef_callbacks(ptr, methods);
}