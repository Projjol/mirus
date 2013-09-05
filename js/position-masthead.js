function getDocHeight() {
    var D = document;
    return Math.max(
        D.body.scrollHeight, D.documentElement.scrollHeight,
        D.body.offsetHeight, D.documentElement.offsetHeight,
        D.body.clientHeight, D.documentElement.clientHeight
    );
}

window.onload = function() {
    var img_height = getDocHeight() - $('#main_head').height();
    $('#masthead').style.height = img_height;
};