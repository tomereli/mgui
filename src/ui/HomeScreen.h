#ifndef SRC_UI_HOMESCREEN_H_
#define SRC_UI_HOMESCREEN_H_

#include "ScreenBase.h"

namespace ilixi
{
class ToolButton;
class Dialog;
}

namespace MGUI
{

class HomeScreen : public ScreenBase
{
public:
	HomeScreen();

	virtual
	~HomeScreen();

private:
	ilixi::ToolButton* _cellular;
	ilixi::ToolButton* _wireless;
};

} /* namespace MGUI */

#endif /* SRC_UI_HOMESCREEN_H_ */
