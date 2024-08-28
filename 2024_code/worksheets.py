""" 
This code generates worksheets consisting of random math multiplication questions
Used as a prototype for my math-site
"""

from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
import random

def generate_multiplication_problems(num_problems=10):
    problems = []
    for _ in range(num_problems):
        num1 = random.randint(1, 10)
        num2 = random.randint(1, 10)
        problem = f"{num1} x {num2} = _______"
        problems.append(problem)
    return problems

def create_pdf(filename, problems):
    c = canvas.Canvas(filename, pagesize=letter)
    width, height = letter
    
    # Title
    c.setFont("Helvetica-Bold", 20)
    c.drawCentredString(width / 2.0, height - 50, "Grade 3 Maths Worksheet")
    
    # Name and Date
    c.setFont("Helvetica", 12)
    c.drawString(width - 200, height - 30, "Name: ________________")
    c.drawString(width - 200, height - 50, "Date: ________________")
    
    # Line separator
    c.line(30, height - 70, width - 30, height - 70)
    
    # Math problems
    c.setFont("Helvetica", 14)
    y = height - 100
    for i, problem in enumerate(problems, 1):
        c.drawString(40, y, f"{i}. {problem}")
        y -= 30  # Move down for the next problem
    
    # Save the PDF
    c.save()


def main():
    num_problems = 10
    problems = generate_multiplication_problems(num_problems)
    create_pdf("Grade_3_Maths_Worksheet.pdf", problems)

if __name__ == "__main__":
    main()
