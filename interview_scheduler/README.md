# Automated Interview Scheduling System


**Objective**:
Develop a robust and efficient scheduling system to automate the process of matching interviewers and interviewees based on their availability and interview types.

Background:
In a recruitment process, coordinating schedules between multiple interviewers and interviewees can be complex and time-consuming. Both interviewers and interviewees have specific availability slots and may be required for different types of interviews (e.g., Technical, HR, Behavioral). An automated system is needed to streamline this process, ensuring optimal scheduling that minimizes conflicts and maximizes efficiency.

**Requirements**:

## Entities and Attributes:

- Interviewer:
  - ID
  - Name
  - Email
  - Available Slots (time points)
  - Interview Types (e.g., Technical, HR, Behavioral)
- Interviewee:
  - ID
  - Name
  - Email
  - Available Slots (time points)
  - Preferred Interview Types
- Interview:
  - ID
  - Interviewer ID
  - Interviewee ID
  - Interview Type
  - Scheduled Time (time point)

## Functionality:

- Interviewer and Interviewee Creation: Ability to create and initialize interviewers and interviewees with their respective attributes.
- Dynamic Updates: Allow adding new slots and interview types to existing interviewers and interviewees dynamically.
- Scheduling Algorithm: Implement an algorithm to match interviewers and interviewees based on their availability and interview type preferences.
- Error Handling: Robust handling of invalid operations, such as scheduling conflicts or invalid slot numbers.
User Interface:

## Input/Output:

- Input Format: The program should initialize data for interviewers and interviewees, including their available slots and interview types. Dynamic updates should be demonstrated by adding slots and interview types after initial creation.
- Output Format: The program should print the details of the scheduled interviews, including handling any exceptions that may occur.