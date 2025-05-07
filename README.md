# Computer-Arch.-MIPS-Architecture-from-C-to-Assembly
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>MIPS Architecture Project</title>
  <style>
    body {
      margin: 0;
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      background: linear-gradient(180deg, #1f1f1f 0%, #f4f4f4 100%);
      color: #333;
      line-height: 1.7;
    }

    header {
      background-color: #121212;
      color: #fff;
      padding: 40px 20px;
      text-align: center;
      box-shadow: 0 4px 12px rgba(0,0,0,0.5);
    }

    header h1 {
      font-size: 2.8rem;
      margin-bottom: 10px;
      letter-spacing: 1px;
    }

    header p {
      font-size: 1.2rem;
      color: #aaa;
    }

    section {
      max-width: 900px;
      margin: 40px auto;
      background-color: #fff;
      border-radius: 12px;
      padding: 30px;
      box-shadow: 0 8px 20px rgba(0,0,0,0.1);
    }

    section h2 {
      color: #1f1f1f;
      border-left: 5px solid #0077ff;
      padding-left: 15px;
      margin-bottom: 20px;
    }

    code, pre {
      background-color: #f0f0f0;
      color: #333;
      padding: 12px;
      border-radius: 8px;
      display: block;
      overflow-x: auto;
      margin-bottom: 20px;
      font-family: monospace;
    }

    .file-tree {
      background: #eee;
      padding: 12px 20px;
      border-radius: 8px;
      font-family: monospace;
      line-height: 1.6;
    }

    footer {
      text-align: center;
      padding: 20px;
      font-size: 0.9rem;
      color: #aaa;
      background-color: #1f1f1f;
    }
  </style>
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
      └── README.html
    </div>

    <h2>🙋‍♂️ Author</h2>
    <p><strong>Your Name</strong><br>
    Computer Architecture Course - [University Name]</p>
  </section>

  <footer>
    © 2025 | MIPS Architecture Project | ️The Fast Trackers⚡️|| El-Kadya Official Acadimic Team
  </footer>
</body>
</html>
