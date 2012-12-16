Dashboard = {};

// setup event handler
Dashboard.eventHandler = function(event)
{
	if (!TiDev.dashboardAdContent && TiDev.isCommunity != null)
	{
		TiDev.setDashboardContent = true;
		return;
	}
	else if (TiDev.isCommunity == null)
	{
		$('#dashboard_offline').css('display','block');
		return;
	}
	if (event == 'focus' || event == 'load')
	{
		$('#dashboard').html(TiDev.dashboardAdContent);
		Dashboard.setupView();
	}

};


//
// Setup UI view
//
Dashboard.setupView = function()
{
	TiUI.setBackgroundColor('#06284D');
	TiDev.contentLeft.hide();
	TiDev.contentLeftHideButton.hide();
	TiDev.contentLeftShowButton.hide();
};


// register module
TiDev.registerModule({
	name:'dashboard',
	displayName: '<u>D</u>ashboard',
	perspectives:['projects'],
	html:'dashboard.html',
	idx:0,
	//active:true,
	callback:Dashboard.eventHandler
});

