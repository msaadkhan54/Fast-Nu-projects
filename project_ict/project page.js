// script.js

// Hover functionality for project details
document.querySelectorAll('.project-card').forEach((card) => {
    card.addEventListener('mouseenter', () => {
      const details = card.querySelector('.project-details');
      if (details) details.style.display = 'block';
    });
  
    card.addEventListener('mouseleave', () => {
      const details = card.querySelector('.project-details');
      if (details) details.style.display = 'none';
    });
  });
  
  // Dark Mode Toggle
  const darkModeToggle = document.getElementById('darkModeToggle');
  
  darkModeToggle.addEventListener('click', () => {
    document.body.classList.toggle('dark-mode');
    
    // Change button text based on mode
    if (document.body.classList.contains('dark-mode')) {
      darkModeToggle.textContent = 'Light Mode';
    } else {
      darkModeToggle.textContent = 'Dark Mode';
    }
  });
  