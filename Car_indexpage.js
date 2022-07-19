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