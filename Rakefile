# Copyright 2013 Joshua Beitler

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

# http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# dependencies
require 'rubygems'
require 'colorize'
require 'artii'
require './build/lib/deps'

# check for required programs
if meets_deps? == false
    puts "Does not meet dependencies, cannot continue.".red
    exit
end

# require all our tasks
require './build/lib/env'
require './build/lib/tasks/all'
require './build/lib/tasks/iso'
require './build/lib/tasks/asm'
require './build/lib/tasks/clean'
require './build/lib/tasks/kernel'
require './build/lib/tasks/qemu'
require './build/lib/tasks/configure'
require './build/lib/tasks/link'

directory "./build/logs"

# cool ascii art
a = Artii::Base.new :font => 'slant'
puts a.asciify('mirus')
puts "Mirus build system [0.2.0]"
puts "(C) Mirus Project, Apache 2 License"

puts

# default task is to generate an iso image
task :default => ['make_iso'] do
    if $errors
        puts
        puts "Errors were generated during the build.  Please review the \"build/*.log\" files for details.".red
        exit 1
    else
        puts
        puts "Build completed successfully!".green
    end
end
