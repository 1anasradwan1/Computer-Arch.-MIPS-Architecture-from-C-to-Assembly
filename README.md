<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>MIPS Architecture Project</title>
  <link rel="stylesheet" href="style.css" />
</head>
<body>
  <header>
    <h1>MIPS Architecture Project</h1>
    <p>Simulating a Basic MIPS CPU with Datapath & Control Logic</p>
  </header>

  <section>
    <h2>📚 Overview</h2>
    <p>This project simulates a simplified MIPS processor architecture, showcasing fundamental components like the ALU, control unit, register file, and memory. It demonstrates how MIPS instructions are fetched, decoded, and executed in a multi-stage datapath.</p>

    <h2>🎯 Objectives</h2>
    <ul>
      <li>Understand the structure of a basic MIPS processor.</li>
      <li>Simulate instruction execution using a predefined instruction set.</li>
      <li>Practice hardware-level thinking through logic components and datapath design.</li>
    </ul>

    <h2>🏗️ Features</h2>
    <ul>
      <li>5-stage pipeline: IF, ID, EX, MEM, WB</li>
      <li>ALU for arithmetic & logic</li>
      <li>Register File (32-bit)</li>
      <li>Control Unit</li>
      <li>Instruction & Data Memory</li>
    </ul>

    <h2>⚙️ Architecture Components</h2>
    <ul>
      <li><strong>Datapath:</strong> Flow from fetch to write-back</li>
      <li><strong>Control Unit:</strong> Generates control signals</li>
      <li><strong>ALU:</strong> Executes operations</li>
      <li><strong>Register File:</strong> Stores registers</li>
    </ul>

    <h2>🚀 How to Run</h2>
    <ol>
      <li>Clone this repository.</li>
      <li>Open the circuit or simulation file.</li>
      <li>Load sample MIPS instructions and step through execution.</li>
    </ol>

    <h2>🧪 Example Instructions</h2>
    <pre><code>add $t0, $t1, $t2
sub $s1, $s2, $s3
lw $t0, 0($s1)
sw $t2, 4($s1)
beq $t0, $t1, label</code></pre>

    <h2>📁 File Structure</h2>
    <div class="file-tree">
      /project-root<br>
      ├── datapath.circ<br>
      ├── control_unit.v<br>
      ├── memory.v<br>
      ├── test_program.asm<br>
      └── index.html
    </div>

    <h2>🙋‍♂️ Author</h2>
    <p><strong>Your Name</strong><br>
    Computer Architecture Course - [University Name]</p>
  </section>

  <footer>
    © 2025 | MIPS Architecture Project |️The Fast Trackers⚡️|| El-Kadya Official Acadimic Team
  </footer>
</body>
</html>

