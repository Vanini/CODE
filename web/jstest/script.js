function StartTime() {
	data = new Date();
	sec = f(data.getSeconds());
	min = f(data.getMinutes());
	hour = f(data.getHours());
	clock.innerHTML = hour + ":" + min + ":" + sec;
	setTimeout("StartTime()", 900);
}
function f(a) {
	if (a < 10) a = '0' + a;
	return a;
}
