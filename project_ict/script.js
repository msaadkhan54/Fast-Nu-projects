document.addEventListener("DOMContentLoaded", () => {   
const form = document.getElementById("contact-form"); 
const formMessage = document.getElementById("form-message");
   
form.addEventListener("submit", (event) => {   
event.preventDefault();
  
// Display a success message 
formMessage.textContent = "Thank you for reaching out! We will get back to you shortly.";        
formMessage.style.color = "green";        
formMessage.style.marginTop = "15px";
        
// Reset form fields        
form.reset();   
 });});