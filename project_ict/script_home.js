

const greetingDiv = document.getElementById("greeting");
const currentHour = new Date().getHours();
let greetingMessage = "Welcome!";
if (currentHour < 12) {
    greetingMessage = "Good Morning!";
} else if (currentHour < 18) {
    greetingMessage = "Good Afternoon!";
} else {
    greetingMessage = "Good Evening!";
}
greetingDiv.innerText = greetingMessage;
greetingDiv.style.textAlign = "center";
greetingDiv.style.fontSize = "24px";
greetingDiv.style.fontWeight = "bold";

const slideshowImages = [
    "C:\\Users\\Hp i7\\Desktop\\project_ict\\Black Green Modern Digital Marketing Open to Work LinkedIn Banner.jpg", // First image
    "C:\\Users\\Hp i7\\Desktop\\project_ict\\Blue Modern Company Slogan LinkedIn Banner.jpg", // Second image
    "C:\\Users\\Hp i7\\Desktop\\project_ict\\Green and Blue Modern Business Promo LinkedIn Article Cover Image.jpg" // Third image
];
let currentImageIndex = 0;
const slideshowElement = document.getElementById("slideshow-img");

function changeSlideshowImage() {
    currentImageIndex = (currentImageIndex + 1) % slideshowImages.length;
    slideshowElement.src = slideshowImages[currentImageIndex];
}
setInterval(changeSlideshowImage, 3000); 



