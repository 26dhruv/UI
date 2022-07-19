const user = document.getElementById("Username")
const pass = document.getElementById("Password")
document.querySelector("#Signinbtn").addEventListener("click", () => {
    if (user.value == "Dhruvesh" && pass.value == "dhruvesh.123") {
        window.location.href = "Car_Code.html"
    }
    else if (user.value == "Dhruv" && pass.value == "dhruv.123") {
        window.location.href = "Car_Code.html"
    }
})
let lock = document.getElementById("lock")
let unlock = document.getElementById("unlock")
lock.style.opacity = 100;
lock.addEventListener("click", () => {
    if (pass.type == "password") {
        pass.setAttribute("type", "text");
        lock.style.opacity = 0;
        unlock.style.opacity = 100;

    }
    else {
        pass.setAttribute("type", "password");
        lock.style.opacity = 100;
        unlock.style.opacity = 0;
    }
})