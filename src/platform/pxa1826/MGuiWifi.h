#ifndef SRC_MGUI_WIFI_H_
#define SRC_MGUI_WIFI_H_

#include "UBusClient.h"
#include "WifiRequest.h"

namespace MGUI
{

class WifiRequest;

class MGuiWifi : public UBusClient
{

public:
	static MGuiWifi*
	Instance();

	int
	Indication(struct ubus_context *ctx, struct ubus_object *obj,
		      struct ubus_request_data *req,
		      const char *method, struct blob_attr *msg);

	static int
	Create(ubus_context *ubus, StatusBar *bar, ilixi::ToolButton* button);

	static void
	Destroy();

	virtual int
	Register();

	virtual int
	UnRegister();

	int
	Update(blob_attr *msg);

protected:
	MGuiWifi(ubus_context* ubus, StatusBar* bar, ilixi::ToolButton* button);

	virtual
	~MGuiWifi();

private:
	enum {
		ATTR_WIRELESS = 0,
		ATTR_WIFI_IF_2G,
		ATTR_WIFI_IF_5G,
		ATTR_DEVICE,
		ATTR_SWITCH,
		ATTR_CHANNEL,
		ATTR_SSID,
		NR_ATTR,
	};

	static const blobmsg_policy _policy[NR_ATTR];

	struct wifi_status {
		std::string device;
		std::string on;
		std::string channel;
		std::string ssid;
	} _status;

	int
	parseattrs_tag(blob_attr *msg);

	static MGuiWifi* _instance;
	WifiRequest* _request;
	StatusBar* _bar;
	ilixi::ToolButton* _button;
};

} /* namespace MGUI */

#endif /* SRC_MGUI_CHARGER_H_ */
